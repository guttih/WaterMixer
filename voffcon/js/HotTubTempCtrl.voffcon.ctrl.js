"use strict";
/*
    Use this control to display the state of a hottub
*/
class HotTubTempCtrl extends ControlElement {
    constructor(idExtender, left, top, width, height, statusResponse) {
        super('hot-tub-temp-ctrl', idExtender, left, top);
        var svg = super.getSvg();
        svg.attr('width', width);
        svg.attr('height', height);

        this.init(statusResponse);
    }
    calculateWaterLevel(downloadLogs) {
        if (downloadLogs === true) {
            this.getLogs((data) => {
                this.log = data;
                this.calculateWaterLevel(false);
            });
            return;
        }
        var start = 0;
        var data = JSON.parse(JSON.stringify(this.log));
        data.forEach(element => {
            element.data = JSON.parse(element.data);
        });
        data[start].flow = 0;
        data[start].flowSeconds = 0;
        data[start].flowUnits = 0;
        data[start].sumFlowUnits = 0;

        data.push({
            datetime: new Date().toString(),
            flow: 0,
            flowSeconds: 0,
            flowUnits: 0,
            sumFlowUnits: 0,
            waterLevel: 0,

            data: [
                { "pin": 50, "val": this.hotValveFlow * 1023, "m": 4, "name": "valveHot" },
                { "pin": 51, "val": this.coldValveFlow * 1023, "m": 4, "name": "valveCold" },
                { "pin": 52, "val": this.drainValveFlow * 1023, "m": 4, "name": "valveDrain" },
                { "pin": 53, "val": this.currentPressure * 1023, "m": 4, "name": "pressure" },
                { "pin": 54, "val": this.currentTemperature * 1023, "m": 4, "name": "temperature" },
                { "pin": 55, "val": this.desiredTemperature * 1023, "m": 4, "name": "desiredTemperature" }
            ]

        });

        for (var i = start + 1; i < data.length; i++) {
            data[i].date = new Date(data[i].datetime);
            this.calculateWatherFlow(data[i - 1], data[i], i);
        }

        this.setWaterLevel(data[data.length - 1].waterLevel);

        setTimeout(() => {
            this.calculateWaterLevel(false);
        }, 5000);
    }
    calculateWatherFlow(prevObject, currentObject) {

        var fillFlowUnits = this.fillSeconds * 1023;
        var prevDate = new Date(prevObject.datetime);
        var currDate = new Date(currentObject.datetime);
        var diffMillis = (currDate.getTime() - prevDate.getTime());
        var diffSeconds = (diffMillis / 1000);
        var drainValue = prevObject.data.filter(item => item.name === "valveDrain")[0].val;
        var hotValue = prevObject.data.filter(item => item.name === "valveHot")[0].val;
        var coldValue = prevObject.data.filter(item => item.name === "valveCold")[0].val;
        var fillValue = coldValue > hotValue ? coldValue : hotValue;
        if (drainValue > 0) {
            currentObject.flow = drainValue * (this.fillSeconds / this.drainSeconds) * -1;
        } else {
            currentObject.flow = fillValue;
        }


        currentObject.flowSeconds = diffSeconds;
        currentObject.flowUnits = diffSeconds * currentObject.flow;

        currentObject.sumFlowUnits = prevObject.sumFlowUnits + currentObject.flowUnits;
        if (currentObject.sumFlowUnits < 0) {
            currentObject.sumFlowUnits = 0;
        } else if (currentObject.sumFlowUnits > fillFlowUnits) {
            currentObject.sumFlowUnits = fillFlowUnits;
        }
        //currentObject.waterLevel = Math.round((currentObject.sumFlowUnits / fillFlowUnits) * 1000);
        currentObject.waterLevel = (currentObject.sumFlowUnits / fillFlowUnits) * 100;
        // console.log(`,${formaTima(currDate)},${currentObject.flowSeconds},${currentObject.flow},${currentObject.sumFlowUnits},${currentObject.waterLevel}`);
    }
    getServer(){
        return window.location.protocol + '//' + window.location.hostname + (window.location.port ? ':' + window.location.port : '');
    }

    getLogs(resolve) {
        var url = this.getServer() + '/logs/list/' + this.deviceId;
        var request = $.get(url);
        request.done(function (data) {
            if (data.length < 1) {
            } else {
                this.logger = data;
                resolve(data);
            }
        }).fail(function (data) {
            console.log("rejecting");
            reject(data);
        });
    }

    init(statusResponse) {
        this.deviceId = statusResponse.deviceId;
        this.log = [];
        // DrainTimeRequired : 10:00:00 -> 10*60*60   = 36000 sec
        // FillTimeRequired  : 00:48:56 -> (48*60)+56 = 2934 sec
        // FillTimeRequired  : 01:10:00 -> (70*60)+0 = 4200 sec
        this.setFlowTimeInSeconds(2934, 36000);
        this.setStatus(statusResponse);
        var that = this;
        this.getUpdateButton().on('click', function (e) {
            var currentVal = that.getDesiredTemperatureInput().val();
            var sendObj = {
                cmd:'update',
                temperature: currentVal
            };
            var url = that.getServer()+'/devices/custom/'+ that.deviceId;
            // console.log(`Sending ${url}\n${JSON.stringify(sendObj, null, 4)}`);
            var posting = $.post( url, sendObj);
            // posting.done(function(data){
            //     console.log(`response: ${JSON.stringify(data, null, 4)}`);
            // });
            // this.desiredTemperature
            // console.log(currentVal)
            that.calculateWaterLevel(true);
        });
        this.calculateWaterLevel(true);
    }
    isFilling() { return this.coldValveFlow > 0 || this.hotValveFlow > 0; }
    isDraining() { return this.drainValveFlow > 0; }
    isStopped() { return this.coldValveFlow === 0 && this.hotValveFlow === 0 && this.drainValveFlow === 0; }

    setStatus(status) {
        this.hotValveFlow = status.mixer.hotValveFlow;
        this.coldValveFlow = status.mixer.coldValveFlow;
        this.currentPressure = status.mixer.currentPressure;
        this.currentTemperature = status.mixer.currentTemperature;
        this.desiredTemperature = status.mixer.desiredTemperature;
        this.drainValveFlow = status.mixer.drainValveFlow;
        this.mode = status.mixer.mode;
        if (this.isStopped()) {
            //when all is stopped, we can read the waterlevel from pressure sensor
            this.setWaterLevel((this.currentPressure / 0.46) * 100);//pressure 0.46 means full
            this.stop();
        } else if (this.isFilling()) {
            this.drawFill(this.hotValveFlow, this.coldValveFlow);
        } else if (this.isDraining()) {
            this.drain();
        }

        this.getDesiredTemperatureInput().val(this.desiredTemperature);
        this.getCurrentTemperatureDiv().text(this.currentTemperature);
        this.getCurrentPressureDiv().text(this.currentPressure);
        //super.scale($('#' + super.getId()), value);
    }
    scale(value) {
        super.scale(this.getLight(), value);
        //super.scale($('#' + super.getId()), value);
    }
    rotate(degrees) {
        super.rotate(this.getLight(), degrees);
    }
    getBlob() {
        return $('#' + super.getId() + ' div.blob');
    }
    getLine() {
        return $('#' + super.getId() + ' > svg > line');
    }
    getDesiredTemperatureInput() {
        return $('#' + super.getId() + ' input[name="desired-temperature"]');
    }
    getCurrentTemperatureDiv() {
        return $('#' + super.getId() + ' .current-temperature-value');
    }
    getCurrentPressureDiv() {
        return $('#' + super.getId() + ' .current-pressure-value');
    }
    getWaterLevelText() {
        return $('#' + super.getId() + ' div.water-level-text');
    }
    getFlowText() {
        return $('#' + super.getId() + ' div.flow-text');
    }
    getUpdateButton() {
        return $('#' + super.getId() + ' .btn-update');
    }

    setValue(value) {

        if (this.drainPin.value > 0) {
            this.drain();

        } else if (this.fillPin.value > 0) {
            this.fill(this.fillPin.value);
        } else {
            this.stop();
        }
        this.active(true);
    }

    active(isActive) {
        var classRemoving, classAdding;
        if (isActive) {
            classRemoving = 'set-inactive'; classAdding = 'set-active';
        } else {
            classRemoving = 'set-active'; classAdding = 'set-inactive';
        }
        this.getBlob().removeClass(classRemoving).addClass(classAdding);
        this.getLine().removeClass(classRemoving).addClass(classAdding);

    }
    fill(hotFlow, coldFlow) {
        if (value === 0) {
            this.stop();
        } else {
            this.drawFill(hotFlow, clodFlow);
            this.reCalculate();
        }
    }
    reCalculate(waitDelay = 20000) {
        console.log(`Fetching logs again after ${waitDelay / 1000} seconds, for re-calculation`);
        setTimeout(() => {
            console.log('Recalculating water level');
            this.calculateWaterLevel(true);
        }, waitDelay);
    }
    drain() { this.drawDrain(); this.reCalculate(); }
    stop() { this.drawStop(); this.reCalculate(); }

    drawFill(hotFlow, clodFlow) {
        var value = hotFlow > clodFlow ? hotFlow : clodFlow;
        var maxSpeed = 0.95, minSpeed = 7.0, maxNegative = (minSpeed - maxSpeed);
        var ratio = value / 100;
        var negative = ratio * maxNegative;
        var speed = minSpeed - negative;
        speed *= 100; speed = Math.round(speed); speed /= 100;
        var dur = speed + 's';
        this.getBlob().removeClass('hiding').addClass('showing');
        this.getBlob().removeClass('drain-hottub').addClass('fill-hottub');
        this.getBlob().css("animation-duration", function (index) {
            return speed + 's';
        });
    }

    drawStop() {
        this.getBlob().removeClass('showing').addClass('hiding');
    }

    drawDrain() {
        var blob = this.getBlob();
        this.getBlob().removeClass('hiding').addClass('showing');
        this.getBlob().removeClass('fill-hottub').addClass('drain-hottub');
        this.getBlob().css("animation-duration", function (index) {
            return '2s';
        });
    }

    setWaterLevel(procent) {
        this.waterLevel = procent;
        // this.waterLevel = Math.round(procent * 10) / 10;//round to one decimals

        this.drawWaterLevel();
    }

    /**
     * 
     * @param {How many seconds does it take to completely fill the hot tub} fillTimeRequiredInSeconds 
     * @param {How many seconds does it take to completely drain the hot tub} drainTimeRequiredInSeconds 
     */
    setFlowTimeInSeconds(fillTimeRequiredInSeconds, drainTimeRequiredInSeconds) {
        this.fillSeconds = fillTimeRequiredInSeconds;
        this.drainSeconds = drainTimeRequiredInSeconds;
        this.fillMinutes = this.fillSeconds / 60;
    }

    drawWaterLevel() {
        if (this.waterLevel < 0) {
            this.waterLevel = 0;
        } else if (this.waterLevel > 100) {
            this.waterLevel = 100;
        }

        var waterLevelText = `${Math.round(this.waterLevel * 10) / 10}%`;

        // cy   = 75 when waterLevel === 100
        // cy   = 120 when waterLevel === 0
        // diff = 45 when waterLevel === 100
        var MAX = 120, MIN = 75, DIFF = MAX - MIN, add;
        var cx, cy, rx, ry, steps = 20;
        add = DIFF * (this.waterLevel / 100);
        cx = 223; cy = MAX - add; rx = 88; ry = 26;
        //cx="223" cy="87" rx="88" ry="26"

        if (this.waterLevel > 83) {

            var cyDiff = -16, rxDiff = 11, ryDiff = 5,
                cyChange, rxChange, ryChange;
            var stepCount = (100 - this.waterLevel);
            var portion = stepCount / steps;
            cyChange = portion * cyDiff;
            rxChange = portion * rxDiff;
            ryChange = portion * ryDiff;
            cy = 71 - cyChange;
            rx = 100 - rxChange;
            ry = 31 - ryChange;
        }

        var $elm = $('ellipse.vatn');
        $elm.attr('cx', cx);
        $elm.attr('cy', cy);
        $elm.attr('rx', rx);
        $elm.attr('ry', ry);

        if (this.waterLevel === 0) {
            $elm.removeClass('blatt').addClass('bottom-hottub');
        }
        else {
            $elm.removeClass('bottom-hottub').addClass('blatt');
        }

        this.getWaterLevelText().text(waterLevelText);
        this.getFlowText().text(" ");
        if (this.fillPin !== undefined && this.fillMinutes !== undefined
            && (this.fillPin.value > 0 || this.drainPin.value > 0)) {

            var minutesLeft = 0, power = 0, hours = 0, minutes = 0;
            if (this.fillPin.value > 0) {
                var missingWater = 100 - this.waterLevel;
                power = this.fillPin.value / 1023;
                minutesLeft = (missingWater / 100) * this.fillMinutes / power;
            } else if (this.drainPin.value > 0) {
                power = this.drainPin.value / 1023;
                minutesLeft = (this.waterLevel / 100) * this.drainSeconds / power;
            }

            var hoursFrag = minutesLeft / 60;
            hours = parseInt(hoursFrag);
            minutes = Math.round((hoursFrag - hours) * 60);

            //full after
            var remainingTimeString = zeroFirst(hours) + ':' + zeroFirst(minutes);
            //this.getFlowText().text(zeroFirst(hours)+':'+ zeroFirst(minutes));


            //full at
            var d = new Date(); // for now
            d.setHours(d.getHours() + hours);
            d.setMinutes(d.getMinutes() + minutes);

            var timeFull = d.getHours() + ':' + d.getMinutes();
            this.getFlowText().text(`${timeFull} (${remainingTimeString})`);
        }
    }
}//class

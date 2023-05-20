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
            //this.getDeviceLogs(deviceId);
            console.log("fetcing logs");
        }
        console.log("calulating");
        console.log(this);
    }
    init(statusResponse) {
        this.deviceId = statusResponse.deviceId;
        var elm = this.getRefreshButton();
        var thatCalculateWaterLevel = this.calculateWaterLevel;
        elm.on('click', function (e) {
            console.log('You, clicke d inty');
            thatCalculateWaterLevel(true);
        });

        this.setStatus(statusResponse);
        this.calculateWaterLevel(true);

    }
    isFilling() { return this.coldValveFlow > 0 || this.hotValveFlow > 0; }
    isDraining() { return this.drainValveFlow > 0; }
    isStopped() { return this.coldValveFlow === 0 && this.hotValveFlow === 0 && this.drainValveFlow === 0; }

    setStatus(status) {
        console.log(status);
        this.hotValveFlow = status.mixer.hotValveFlow;
        this.coldValveFlow = status.mixer.coldValveFlow;
        this.currentPressure = status.mixer.currentPressure;
        this.currentTemperature = status.mixer.currentTemperature;
        this.desiredTemperature = status.mixer.desiredTemperature;
        this.drainValveFlow = status.mixer.drainValveFlow;
        this.mode = status.mixer.mode;
        console.log(this);
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
    getRefreshButton() {
        return $('#' + super.getId() + ' .btn-refresh');
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
        }
    }

    drain() { this.drawDrain(); }
    stop() { this.drawStop(); }

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
        this.waterLevel = Math.round(procent * 100) / 100;//round to two decimals
        this.drawWaterLevel();
    }
    setFlowTimeInMinutes(fillMinutes, drainMinutes) {
        this.fillMinutes = fillMinutes;
        this.drainMinutes = drainMinutes;
    }

    drawWaterLevel() {
        if (this.waterLevel < 0) {
            this.waterLevel = 0;
        } else if (this.waterLevel > 100) {
            this.waterLevel = 100;
        }
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
        this.getWaterLevelText().text(this.waterLevel + '%');
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
                minutesLeft = (this.waterLevel / 100) * this.drainMinutes / power;
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
    getDeviceLogs(deviceId) {
        var SERVER = window.location.protocol + '//' + window.location.hostname + (window.location.port ? ':' + window.location.port : '');
        var url = SERVER + '/logs/list/' + deviceId;
        var request = $.get(url);
        request.done(function (data) {
            if (data.length < 1) {
                console.log("data empty:");
                return;

            } else {
                console.log("We got data!!!!");
                console.log(data);
            }
            // var start = 0;
            // var drainFlowUnits = hotTub.drainMinutes*1023, // five hours on full flow
            //     fillFlowUnits = hotTub.fillMinutes *1023;
            // data[start].flow      =0;
            // data[start].flowMinutes=0;
            // data[start].flowUnits  =0;
            // data[start].sumFlowUnits   =0;
            // for(var i = start+1; i<data.length;i++) {
            //     data[i].date = new Date(data[i].datetime);
            //     calculateWatherFlow(data[i-1], data[i],i);
            // }

            // var lastState = data[data.length-1];
            // var now = { 
            //             datetime    : new Date().toString(),
            //             flow        : 0,
            //             flowMinutes : 0,
            //             flowUnits   : 0,
            //             sumFlowUnits: 0,
            //             waterLevel  : 0

            // };
            // calculateWatherFlow(lastState, now);
            // hotTub.setWaterLevel(now.waterLevel);

        }).fail(function (data) {
            if (data.status === 401) {
                showModal("You need to be logged in!", data.responseText);
            }
        });
    }
}//class

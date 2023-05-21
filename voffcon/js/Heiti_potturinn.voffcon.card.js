var using = ["TextPinCtrl","HotTubTempCtrl", "SwitchCtrl", "SvgCtrl","SliderCtrl","TextCtrl"];

var device, switchDrain, hotTub;
var pinFill, pinDrain;
var switchFill, switchDrain;

var setupAppPins = function setupAppPins(device, xBase, yBase, statusResponse){

var bak = new SvgCtrl('bakgrunnur', 0,30, 200,200);
    //pinFill = device.get(5);
    //pinDrain = device.get(4);
    
    
    bak.addText(60,43, "Fylla");
    bak.addText(38,152, "Tæma");
    /*var timi = new TextCtrl(145,240, 'Fylla tekur 1 klst og 54 min');*/
    
    var pinCount = device.pins.length;
    
    hotTub = new HotTubTempCtrl('hot-tub', xBase, yBase, 330,185, statusResponse);
    
    pinFill = new Pin(5, 0, device.savedDeviceID, 100, device.savedDeviceID);
    pinDrain = new Pin(4, 0, device.savedDeviceID, 100, device.savedDeviceID);
    
    
    //fillPin
    var slider = new SliderCtrl(xBase + 110, 18, pinFill);
    var fillNum = new TextPinCtrl(310,15, pinFill);
    fillNum.scale(1.5);
    slider.getSlider().css('width', '180px');
    switchFill = new SwitchCtrl(xBase + 10, 0, pinFill, 100);
    switchFill.scale(0.7);
    
    //drainPin
    
    // normal                      01:54        06:00
    //hotTub.setFlowTimeInMinutes((54 + (60*1)), 60*6 );
    // when hottub is leaking      02:30         05:30
    switchDrain = new SwitchCtrl(xBase + 10, 110, pinDrain);
    switchDrain.scale(0.7);
    switchDrain.rotate(180);
    
    pinDrain.setValue(hotTub.isDraining()? 100 : 0);
    pinFill.setValue(hotTub.isFilling()? 100 : 0);
    
    pinFill.registerClicks(onClickCAllbackFill);
    pinDrain.registerClicks(onClickCAllbackDrain);
    
    //updateView(device, device.pinsToSendArray());
    
    var t0 = new TextCtrl(360,0, 'Á meðan er verið að renna í pottinn á þá er þrýstingur:');
    var t1 = new TextCtrl(380,20, '- Þegar potturinn er tómur þá: 2.85, 2.86, 2.87 BAR SÁ LÍKA 2.80 SEINNA');
    var t2 = new TextCtrl(380,58, '- Þegar potturinn er fullur þá: 2.94 to 2.97 BAR');
    var t3 = new TextCtrl(380,70, '- Það hefur mikil áhrif hve mikið er opið fyrir heita lokann.  Þrýstingur eykst ef meira er opnað fyrir heita vatnið');
    t0.getElement().css('color','Green');
    t1.getElement().css('color','blue');
    t2.getElement().css('color','red');
    
    
    
    
};



function updateView(device, pinValues ) {
    console.log("todo: get status and update view");
    /*var drainPin = pinDrain.number, fillPin = pinFill.number;
      var pinObj, val;
      console.log('updateView');console.log(pinValues);
        for(var i = 0; i<pinValues.length;i++){
            pinObj = device.get(pinValues[i].pin);
            val    = pinValues[i].val;
            pinObj.setValue(val);
        }
        */
}

function fetchDeviceStatus() {

    
    var posting = $.get(getServer()+'/devices/status/'+device.savedDeviceID);
    
    
    
    posting.done(function(data){
        hotTub.setStatus(data);
        
        //switchDrain.setValue(hotTub.isDraining()? 100 : 0);
        pinDrain.setValue(hotTub.isDraining()? 100 : 0);
        pinFill.setValue(hotTub.isFilling()? 100 : 0);
        //switchFill.setValue(hotTub.isFilling()? 100 : 0);
       
        
        switchDrain.active(true);
        switchFill.active(true);
    })
    .fail(function(data){
        console.log("failed getting hot tub status status");
        if (errorCallback!==undefined){
            console.log(data);
            errorCallback(data);
        }
    });
}

function drawControls(xOff, yOff){
    var x = xOff+25,
        y = yOff-20;
    
    //var posting = $.get(getServer()+'/devices/pins/'+this.savedDeviceID);
    console.log(`device.ID:${device.savedDeviceID}`);
    var posting = $.get(getServer()+'/devices/status/'+device.savedDeviceID);
    
    posting.done(function(data){
         setupAppPins(device, xOff, yOff, data);
    })
    .fail(function(data){
        console.log("failed getting hot tub status status");
            console.log(data);
    });
    
    /*device.fetchAllPins(
        function(){ setupAppPins(device, xOff, yOff); } , 
         setupFailed
    );*/
}

function newDataToView(data){
    var pinNumber, newValue;
    console.log("newDataToView");console.log(data);
    for(var i = 0;i<data.pins.length;i++){
        pinNumber = data.pins[i].pin;
        if (pinNumber === pinDrain.number  || pinNumber === pinFill.number ) {   
            newValue = data.pins[i].val;
            device.get(pinNumber).setValue(newValue);
        }
    }
    //etWaterLevel(device);
}

function onClickCAllbackDrain(obj){
    var pin = obj.pinObject;
    pin.active(false);
    console.log(pin);
    var sendObj = {
        cmd:pin.value == 0? "drain" : "stop"
    };
    //pin.setValue(pin.value === 0? 100:0);
    //sen
    var url = getServer()+'/devices/custom/'+ pin.savedDeviceID;
    var posting = $.post( url, sendObj);
    posting.done(function(data){
       fetchDeviceStatus();
    });
}

function onClickCAllbackFill(obj){
    var pin = obj.pinObject;
    pin.active(false);
    
    var sendObj = {
         cmd:pin.value == 0? "fill" : "stop",
         temperature:Number(hotTub.getDesiredTemperatureInput().val())
    };
    //pin.setValue(pin.value === 0? 100:0);
    //sendObj[pin.number] =  obj.pinValue;
    var url = getServer()+'/devices/custom/'+ pin.savedDeviceID;
    hotTub.stop();
    var posting = $.post( url, sendObj);
    console.log(url);
    console.log(sendObj);
    posting.done(function(data){
        fetchDeviceStatus();
    });
}



function displayError(title, message){
    showModal(title, 
            '\n\n<p class="error-response-text">Error :<br>' + 
            message + '</p>');
}

var setupFailed = function (data){
    console.error('Næ ekki sambandi við stýritæki pottsins');
    console.error(data);
    displayError("Tengivilla", "Næ ekki sambandi við stýringu pottsins");
};


$(function () {
    device = new Device('61052c38bc1fdd0526aedf31', 100);
    drawControls(10, 50);
    //$('body').css("background","rgb(51, 22, 51)");
});
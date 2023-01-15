const char MAIN_page[] PROGMEM = R"=====(


<style>
  body {background-color: #FF0000; font-family: Times; font-size: 400% ; text-align: center; margin:1px auto; padding-top: 300px; width:auto; user-select: none;}
</style>
<body>      
  <h1 style="font-size:80%;">Needs a Bluetooth Controller - None Connected  press @B on the bluetooth controller and another button to activate</h1>
</body>

<script type="text/javascript">
// global gamepad object
let gamepadIndex;
window.addEventListener('gamepadconnected', (event) => {
  gamepadIndex = event.gamepad.index;
});
//int counter = 0;
setInterval(() => {
  if(gamepadIndex !== undefined) {
    // a gamepad is connected and has an index
   
    const myGamepad = navigator.getGamepads()[gamepadIndex];
    document.body.style.backgroundColor = "green" ;
    document.body.innerHTML = "   Go Wild!"; // reset page
 
    let x = myGamepad.axes[0];
    let y = myGamepad.axes[1];
        
    if(y > 0.5){toggle("I");}  // spin left
       
    if(y < -.5){toggle("J");}  // spin right
         
    if(x > 0.5){toggle("G");}  //  back
     
    if(x < -.5){toggle("B");}  //  forward
     
  
   
    myGamepad.buttons.map(e => e.pressed).forEach((isPressed, buttonIndex) => { 
      if(isPressed) {
        if(buttonIndex == 0){ toggle("D");}
        if(buttonIndex == 1){ toggle("G");}
        if(buttonIndex == 2){ toggle("B");}
        if(buttonIndex == 3){ toggle("E");}
        if(buttonIndex == 4){ toggle("off");}

        // button is pressed; indicate this on the page
        //document.body.innerHTML += `<h1>Button ${buttonIndex} is pressed  </h1>`;
      
      }
    })
   
   
  }
}, 100) // print buttons that are pressed 10 times per second

   function toggle(x) {
     var xhr = new XMLHttpRequest();
     xhr.open("GET", "/" + x, true);
     xhr.send();
   }

</script>

)=====";

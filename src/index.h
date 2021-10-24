const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE HTML>

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <title></title>
  <meta name="description" content="">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="">
</head>

<body>

  Switch manually GPIO state
  <br><br>

  <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
    <input type="hidden" name="relay" value="on">
    <button type='submit' style='width:200px; height:100px;'>on</button><br>
  </form>

  <br><br>

  <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
    <input type="hidden" name="relay" value="off">
    <button type='submit' style='width:200px; height:100px;'>off</button><br>
  </form>

  <br><br>

  <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
    <input type="hidden" name="relay" value="timer">
    <button type='submit' style='width:200px; height:100px;'>timer</button><br>
    durée timer
    <input type="number" name="duration" min="1" value="3" style="width:100px;">
  </form>

  <br><br>

  <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
    <input type="hidden" name="relay" value="blink">
    <button type='submit' style='width:200px; height:100px;'>blink</button><br>
    durée on
    <input type="number" name="durationBlinkOn" min="1" value="3" style="width:100px;"><br>
    durée off
    <input type="number" name="durationBlinkOff" min="1" value="3" style="width:100px;"><br>
  </form>

</body>

</html>
)=====";
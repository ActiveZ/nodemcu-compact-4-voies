const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE HTML>

<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title></title>
    <meta name="description" content="">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="">
    <style>
        body {
            background-color: lightgray;
        }

        table {
            font-family: arial, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        td, th {
            border: 1px solid,black;
            text-align: left;
            padding: 8px;
        }

        tr:nth-child(even) {
            background-color: #dddddd;
        }
    </style>
</head>

<body>

    <p>
        Switch manually GPIO state
    </p>

    <table>
        <!-- relai 1 -->
        <tr>
            <td>
                Relai 1
            </td>
            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="on">
                    <input type="hidden" name="pin" value="16">
                    <button type='submit' style='width:200px; height:100px;'>on</button>
                </form>
            </td>


            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="off">
                    <input type="hidden" name="pin" value="16">
                    <button type='submit' style='width:200px; height:100px;'>off</button>
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="timer">
                    <input type="hidden" name="pin" value="16">
                    <button type='submit' style='width:200px; height:100px;'>timer
                        durée timer
                    </button>
                    <input type="number" name="duration" min="1" value="3" style="width:100px;">
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="blink">
                    <input type="hidden" name="pin" value="16">
                    <button type='submit' style='width:200px; height:100px;'>blink
                    </button>
                    durée on
                    <input type="number" name="durationBlinkOn" min="1" value="3" style="width:100px;">
                    durée off
                    <input type="number" name="durationBlinkOff" min="1" value="3" style="width:100px;">
                </form>
            </td>
        </tr>
        <!-- relai 2 -->
        <tr>
            <td>
                Relai 2
            </td>
            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="on">
                    <input type="hidden" name="pin" value="14">
                    <button type='submit' style='width:200px; height:100px;'>on</button>
                </form>
            </td>


            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="off">
                    <input type="hidden" name="pin" value="14">
                    <button type='submit' style='width:200px; height:100px;'>off</button>
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="timer">
                    <input type="hidden" name="pin" value="14">
                    <button type='submit' style='width:200px; height:100px;'>timer
                        durée timer
                    </button>
                    <input type="number" name="duration" min="1" value="3" style="width:100px;">
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="blink">
                    <input type="hidden" name="pin" value="14">
                    <button type='submit' style='width:200px; height:100px;'>blink
                    </button>
                    durée on
                    <input type="number" name="durationBlinkOn" min="1" value="3" style="width:100px;">
                    durée off
                    <input type="number" name="durationBlinkOff" min="1" value="3" style="width:100px;">
                </form>
            </td>
        </tr>
        <!-- relai 3 -->
        <tr>
            <td>
                Relai 3
            </td>
            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="on">
                    <input type="hidden" name="pin" value="12">
                    <button type='submit' style='width:200px; height:100px;'>on</button>
                </form>
            </td>


            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="off">
                    <input type="hidden" name="pin" value="12">
                    <button type='submit' style='width:200px; height:100px;'>off</button>
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="timer">
                    <input type="hidden" name="pin" value="12">
                    <button type='submit' style='width:200px; height:100px;'>timer
                        durée timer
                    </button>
                    <input type="number" name="duration" min="1" value="3" style="width:100px;">
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="blink">
                    <input type="hidden" name="pin" value="12">
                    <button type='submit' style='width:200px; height:100px;'>blink
                    </button>
                    durée on
                    <input type="number" name="durationBlinkOn" min="1" value="3" style="width:100px;">
                    durée off
                    <input type="number" name="durationBlinkOff" min="1" value="3" style="width:100px;">
                </form>
            </td>
        </tr>
        <!-- relai 4 -->
        <tr>
            <td>
                Relai 4
            </td>
            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="on">
                    <input type="hidden" name="pin" value="13">
                    <button type='submit' style='width:200px; height:100px;'>on</button>
                </form>
            </td>


            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="off">
                    <input type="hidden" name="pin" value="13">
                    <button type='submit' style='width:200px; height:100px;'>off</button>
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="timer">
                    <input type="hidden" name="pin" value="13">
                    <button type='submit' style='width:200px; height:100px;'>timer
                        durée timer
                    </button>
                    <input type="number" name="duration" min="1" value="3" style="width:100px;">
                </form>
            </td>

            <td>
                <form method='POST' action='http://frugysoft.freeboxos.fr:8284'>
                    <input type="hidden" name="relay" value="blink">
                    <input type="hidden" name="pin" value="13">
                    <button type='submit' style='width:200px; height:100px;'>blink
                    </button>
                    durée on
                    <input type="number" name="durationBlinkOn" min="1" value="3" style="width:100px;">
                    durée off
                    <input type="number" name="durationBlinkOff" min="1" value="3" style="width:100px;">
                </form>
            </td>
        </tr>

    </table>

</body>

</html>
)=====";
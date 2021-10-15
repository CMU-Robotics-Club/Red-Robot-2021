String html = \
"<html>\n"\
"\n"\
"<head>\n"\
"  <title>Red Robot Controller</title>\n"\
"  <meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no'>\n"\
"  <meta http-equiv='ScreenOrientation' content='autoRotate:disabled'>\n"\
"\n"\
"  <link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/bootswatch@5.1.1/dist/vapor/bootstrap.min.css'\n"\
"    integrity='sha256-UbbKcL7+3mMcL+3j6ea4Nono6ELoTCPSomY2DSK/nYA=' crossorigin='anonymous'>\n"\
"  <script src='https://code.jquery.com/jquery-3.6.0.min.js'\n"\
"    integrity='sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=' crossorigin='anonymous'></script>\n"\
"  <script src='https://cdn.jsdelivr.net/npm/nipplejs@0.9.0/dist/nipplejs.min.js'></script>\n"\
"\n"\
"  <style>\n"\
"    body {\n"\
"      touch-action: none;\n"\
"      user-select: none;\n"\
"      user-zoom: fixed;\n"\
"      pointer-events: visiblePainted;\n"\
"      -webkit-touch-callout: none;\n"\
"    }\n"\
"\n"\
"    .big-button,\n"\
"    .med-button {\n"\
"      line-height: 0;\n"\
"      transition-property: none;\n"\
"    }\n"\
"\n"\
"    .big-button {\n"\
"      font-size: 4.5vw;\n"\
"      width: 8vw;\n"\
"      height: 8vw;\n"\
"      border-radius: 2vw;\n"\
"    }\n"\
"\n"\
"    .med-button {\n"\
"      font-size: 3vw;\n"\
"      width: 6vw;\n"\
"      height: 6vw;\n"\
"      border-radius: 1.5vw;\n"\
"    }\n"\
"\n"\
"    .btn:focus,\n"\
"    .btn:active,\n"\
"    .btn:hover {\n"\
"      background-color: initial;\n"\
"    }\n"\
"\n"\
"\n"\
"    .big-shadow-primary {\n"\
"      box-shadow: 0 0 0.5em var(--bs-primary);\n"\
"    }\n"\
"\n"\
"    .big-shadow-secondary {\n"\
"      box-shadow: 0 0 0.5em var(--bs-secondary);\n"\
"    }\n"\
"\n"\
"    .big-shadow-success {\n"\
"      box-shadow: 0 0 0.5em var(--bs-success);\n"\
"    }\n"\
"\n"\
"    .big-shadow-danger {\n"\
"      box-shadow: 0 0 0.5em var(--bs-danger);\n"\
"    }\n"\
"\n"\
"    .big-shadow-info {\n"\
"      box-shadow: 0 0 0.5em var(--bs-info);\n"\
"    }\n"\
"\n"\
"    .big-shadow-warning {\n"\
"      box-shadow: 0 0 0.5em var(--bs-warning);\n"\
"    }\n"\
"\n"\
"    .big-shadow-light {\n"\
"      box-shadow: 0 0 0.5em var(--bs-light);\n"\
"    }\n"\
"\n"\
"    .big-shadow-dark {\n"\
"      box-shadow: 0 0 0.5em var(--bs-dark);\n"\
"    }\n"\
"  </style>\n"\
"</head>\n"\
"\n"\
"<body class='overflow-hidden'>\n"\
"  <div class='container-fluid h-100 w-100'>\n"\
"    <div class='row h-100'>\n"\
"      <div class='col-sm-4 h-100 d-flex'>\n"\
"        <div id='joystick' class='mx-auto my-auto position-relative'></div>\n"\
"      </div>\n"\
"      <div class='col-sm-4 h-100 d-flex'>\n"\
"        <div class='my-auto mx-auto'>\n"\
"          <div class='row align-content-start'>\n"\
"            <!-- Up/down 1 -->\n"\
"            <div class='col mx-2 px-0'>\n"\
"              <button class='btn big-button btn-outline-success text-success big-shadow-success'\n"\
"                id='up1'>&#9651;</button>\n"\
"              <div class='my-4'></div>\n"\
"              <button class='btn big-button btn-outline-success text-success big-shadow-success'\n"\
"                id='down1'>&#9661;</button>\n"\
"            </div>\n"\
"\n"\
"            <!-- Up/down 2 -->\n"\
"            <div class='col mx-2 px-0'>\n"\
"              <button class='btn big-button btn-outline-warning text-warning big-shadow-warning'\n"\
"                id='up2'>&#9651;</button>\n"\
"              <div class='my-4'></div>\n"\
"              <button class='btn big-button btn-outline-warning text-warning big-shadow-warning'\n"\
"                id='down2'>&#9661;</button>\n"\
"            </div>\n"\
"\n"\
"            <!-- Up/down 3 -->\n"\
"            <div class='col mx-2 px-0'>\n"\
"              <button class='btn big-button btn-outline-danger text-danger big-shadow-danger' id='up3'>&#9651;</button>\n"\
"              <div class='my-4'></div>\n"\
"              <button class='btn big-button btn-outline-danger text-danger big-shadow-danger'\n"\
"                id='down3'>&#9661;</button>\n"\
"            </div>\n"\
"          </div>\n"\
"        </div>\n"\
"      </div>\n"\
"      <div class='col-sm-4 h-100 d-flex align-content-center'>\n"\
"        <div id='joystick2' class='mx-auto my-auto position-relative'></div>\n"\
"        <div id='numpad-container' class='my-auto mx-auto' style='display: none;'>\n"\
"          <div class='d-flex flex-row'>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn1'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>1</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn2'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>2</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn3'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>3</button>\n"\
"            </div>\n"\
"          </div>\n"\
"          <div class='d-flex flex-row'>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn4'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>4</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn5'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>5</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn6'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>6</button>\n"\
"            </div>\n"\
"          </div>\n"\
"          <div class='d-flex flex-row'>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn7'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>7</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn8'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>8</button>\n"\
"            </div>\n"\
"            <div class='text-center'>\n"\
"              <button id='btn9'\n"\
"                class='m-1 btn med-button btn-outline-primary text-primary big-shadow-primary'>9</button>\n"\
"            </div>\n"\
"          </div>\n"\
"        </div>\n"\
"      </div>\n"\
"    </div>\n"\
"    <div class='position-fixed text-center mb-4 w-100' style='bottom: 0'>\n"\
"      <button class='btn btn-outline-light' id='numpad-joystick2-toggle-btn' style='width: 5em; height: 3em;'>\n"\
"        <svg id='numpad-btn-icon' version='1.2' baseProfile='tiny' xmlns='http://www.w3.org/2000/svg' width='24'\n"\
"          height='24' viewBox='0 0 24 24'>\n"\
"          <g color='var(--bs-light)'>\n"\
"            <path stroke='none' fill='currentcolor'\n"\
"              d='M23.292 12.134c.138-.445.208-.91.208-1.384 0-2.619-2.131-4.75-4.75-4.75-1.396 0-2.685.61-3.573 1.632l-.056-.067c-.973-.974-2.349-1.533-3.776-1.533-1.422 0-2.794.556-3.77 1.525-.264-.431-.644-.813-1.122-1.108-.474-.294-1.032-.449-1.613-.449-.482 0-.955.109-1.369.316l-1.406.747c-1.442.721-2.051 2.526-1.313 4.002.272.543.714.982 1.248 1.272v4.663c0 1.654 1.346 3 3 3 .766 0 1.458-.297 1.989-.771.54.487 1.25.771 2.011.771h5c.778 0 1.479-.305 2.01-.795.796.5 1.731.795 2.74.795 2.895 0 5.25-2.355 5.25-5.25 0-.922-.25-1.825-.708-2.616zm-17.292 4.866c0 .552-.448 1-1 1s-1-.448-1-1v-6.382c-.144.072-.306.106-.471.106-.401 0-.813-.203-.988-.553-.247-.494-.031-1.095.463-1.342l1.361-.724c.141-.07.307-.105.475-.105.199 0 .4.05.561.149.294.183.599.504.599.851v8zm8 1h-5c-.404 0-.769-.244-.924-.617-.155-.374-.069-.804.217-1.09l4-4c.254-.254.394-.591.394-.95 0-.358-.14-.695-.394-.949s-.601-.381-.949-.381-.696.127-.952.382c-.252.252-.392.589-.392.948 0 .552-.448 1-1 1s-1-.448-1-1c0-.894.348-1.733.98-2.364.632-.631 1.498-.947 2.364-.947s1.731.316 2.363.948c.632.631.979 1.471.979 2.363 0 .893-.348 1.733-.979 2.364l-2.293 2.293h2.586c.552 0 1 .448 1 1s-.448 1-1 1zm4.75 0c-1.792 0-3.25-1.458-3.25-3.25 0-.552.448-1 1-1s1 .448 1 1c0 .689.561 1.25 1.25 1.25s1.25-.561 1.25-1.25-.561-1.25-1.25-1.25c-.552 0-1-.448-1-1s.448-1 1-1c.414 0 .75-.336.75-.75s-.336-.75-.75-.75c-.281 0-.536.155-.665.404-.178.343-.527.54-.889.54-.155 0-.312-.036-.459-.112-.491-.254-.682-.857-.428-1.348.475-.915 1.41-1.484 2.441-1.484 1.516 0 2.75 1.233 2.75 2.75 0 .611-.207 1.17-.545 1.627.639.594 1.045 1.434 1.045 2.373 0 1.792-1.458 3.25-3.25 3.25z' />\n"\
"          </g>\n"\
"        </svg>\n"\
"        <svg id='joystick-btn-icon' style='display: none;' version='1.1' id='Layer_1' xmlns='http://www.w3.org/2000/svg'\n"\
"          xmlns:xlink='http://www.w3.org/1999/xlink' width='24' height='24' x='0px' y='0px' viewBox='0 0 512 512'\n"\
"          style='enable-background:new 0 0 512 512;' xml:space='preserve'>\n"\
"          <g color='var(--bs-light)'>\n"\
"            <path fill='currentcolor' d='M395.669,128h-35.139c1.399-6.893,2.136-14.027,2.136-21.333C362.667,47.759,314.907,0,256,0\n"\
"				S149.333,47.759,149.333,106.667c0,7.306,0.737,14.44,2.136,21.333h-35.139C87.418,128,64,151.418,64,180.331v279.339\n"\
"				C64,488.582,87.418,512,116.331,512h279.339C424.582,512,448,488.582,448,459.669V180.331C448,151.418,424.582,128,395.669,128z\n"\
"				 M256,341.333c11.782,0,21.333-9.551,21.333-21.333v-36.946c12.75,7.377,21.333,21.153,21.333,36.946\n"\
"				c0,23.567-19.099,42.667-42.667,42.667S213.333,343.567,213.333,320c0-15.793,8.583-29.569,21.333-36.946V320\n"\
"				C234.667,331.782,244.218,341.333,256,341.333z M256,42.667c35.343,0,64,28.657,64,64c0,13.911-4.454,26.776-11.993,37.276\n"\
"				c-0.982,1.023-1.938,2.076-2.84,3.187c-9.824,12.042-23.383,20.044-38.463,22.629c-0.019,0.003-0.039,0.007-0.058,0.01\n"\
"				c-1.033,0.176-2.075,0.318-3.121,0.443c-0.166,0.019-0.329,0.045-0.495,0.063c-0.938,0.104-1.884,0.178-2.831,0.24\n"\
"				c-0.236,0.015-0.47,0.041-0.707,0.054c-1.157,0.063-2.321,0.098-3.49,0.098s-2.333-0.035-3.49-0.098\n"\
"				c-0.237-0.013-0.47-0.038-0.706-0.054c-0.948-0.063-1.895-0.136-2.834-0.24c-0.164-0.018-0.326-0.043-0.489-0.062\n"\
"				c-1.05-0.125-2.096-0.268-3.132-0.445c-0.014-0.002-0.028-0.005-0.043-0.008c-15.085-2.585-28.652-10.594-38.504-22.67\n"\
"				c-0.896-1.103-1.846-2.148-2.821-3.165C196.449,133.428,192,120.57,192,106.667C192,71.323,220.657,42.667,256,42.667z\n"\
"				 M405.333,459.669c0,5.349-4.315,9.664-9.664,9.664H116.331c-5.349,0-9.664-4.315-9.664-9.664V180.331\n"\
"				c0-5.349,4.315-9.664,9.664-9.664h50.24c2.005,0,3.897,0.636,5.447,1.766c15.343,19.565,37.373,33.633,62.649,38.765v26.158\n"\
"				c-36.807,9.472-64,42.88-64,82.645c0,47.131,38.202,85.333,85.333,85.333s85.333-38.202,85.333-85.333\n"\
"				c0-39.765-27.193-73.173-64-82.645v-26.158c25.27-5.13,47.296-19.194,62.639-38.751c1.561-1.143,3.453-1.779,5.457-1.779h50.24\n"\
"				c5.349,0,9.664,4.315,9.664,9.664V459.669z' />\n"\
"            <path fill='currentcolor' d='M192,405.333h-42.667c-11.782,0-21.333,9.551-21.333,21.333S137.551,448,149.333,448H192\n"\
"				c11.782,0,21.333-9.551,21.333-21.333S203.782,405.333,192,405.333z' />\n"\
"            <path fill='currentcolor' d='M362.667,405.333H320c-11.782,0-21.333,9.551-21.333,21.333S308.218,448,320,448h42.667\n"\
"				c11.782,0,21.333-9.551,21.333-21.333S374.449,405.333,362.667,405.333z' />\n"\
"          </g>\n"\
"        </svg>\n"\
"\n"\
"      </button>\n"\
"    </div>\n"\
"\n"\
"    <script>\n"\
"      // Create joystick\n"\
"      var joystickContainer = document.getElementById('joystick');\n"\
"      var joystick = nipplejs.create({\n"\
"        zone: joystickContainer,\n"\
"        mode: 'static',\n"\
"        position: { left: '50%', top: '50%' },\n"\
"        color: 'var(--bs-cyan)',\n"\
"        size: Math.min(joystickContainer.parentElement.offsetWidth, joystickContainer.parentElement.offsetHeight) * 0.6,\n"\
"      });\n"\
"\n"\
"      var joystickContainer2 = document.getElementById('joystick2');\n"\
"      var joystick2 = nipplejs.create({\n"\
"        zone: joystickContainer2,\n"\
"        mode: 'static',\n"\
"        position: { left: '50%', top: '50%' },\n"\
"        color: 'var(--bs-cyan)',\n"\
"        size: Math.min(joystickContainer2.parentElement.offsetWidth, joystickContainer2.parentElement.offsetHeight) * 0.6,\n"\
"      });\n"\
"\n"\
"      var nextEvent = {};\n"\
"      async function tick() {\n"\
"        if (Object.keys(nextEvent).length > 0) {\n"\
"          try {\n"\
"            cachedEvent = JSON.parse(JSON.stringify(nextEvent));\n"\
"            nextEvent = {};\n"\
"            console.log(cachedEvent);\n"\
"            await $.post('/update', cachedEvent);\n"\
"          } catch (err) {\n"\
"            console.error(err);\n"\
"          }\n"\
"        }\n"\
"        setTimeout(tick, 50);\n"\
"      }\n"\
"      tick();\n"\
"\n"\
"\n"\
"      // Bind joystick events\n"\
"      joystick.on('move', function (evt, data) {\n"\
"        var x = data.vector.x;\n"\
"        var y = data.vector.y;\n"\
"\n"\
"        nextEvent.x = x;\n"\
"        nextEvent.y = y;\n"\
"      });\n"\
"\n"\
"      joystick.on('end', function (evt, data) {\n"\
"        nextEvent.x = 0;\n"\
"        nextEvent.y = 0;\n"\
"      });\n"\
"\n"\
"      joystick2.on('move', function (evt, data) {\n"\
"        var x = data.vector.x;\n"\
"        var y = data.vector.y;\n"\
"\n"\
"        nextEvent.x2 = x;\n"\
"        nextEvent.y2 = y;\n"\
"      });\n"\
"\n"\
"      joystick2.on('end', function (evt, data) {\n"\
"        nextEvent.x2 = 0;\n"\
"        nextEvent.y2 = 0;\n"\
"      });\n"\
"\n"\
"      // Bind button events\n"\
"      function onStart(e) {\n"\
"        e.target.classList.add('btn-outline-light');\n"\
"        e.target.classList.add('big-shadow-light');\n"\
"        e.target.classList.add('text-light');\n"\
"        e.preventDefault();\n"\
"\n"\
"        var id = e.target.id;\n"\
"        nextEvent[id] = true;\n"\
"      };\n"\
"      function onEnd(e) {\n"\
"        e.target.classList.remove('btn-outline-light');\n"\
"        e.target.classList.remove('big-shadow-light');\n"\
"        e.target.classList.remove('text-light');\n"\
"        e.preventDefault();\n"\
"\n"\
"        var id = e.target.id;\n"\
"        if (id in nextEvent) {\n"\
"          delete nextEvent[id];\n"\
"        } else {\n"\
"          nextEvent[id] = false;\n"\
"        }\n"\
"      };\n"\
"\n"\
"      var buttons = document.querySelectorAll('.big-button,.med-button');\n"\
"      for (var b of buttons) {\n"\
"        b.addEventListener('touchstart', onStart);\n"\
"        b.addEventListener('mousedown', onStart);\n"\
"        b.addEventListener('touchend', onEnd);\n"\
"        b.addEventListener('mouseup', onEnd);\n"\
"      }\n"\
"\n"\
"      var showJoystick2 = true;\n"\
"      var numpad_joystick2_toggle_btn = document.getElementById('numpad-joystick2-toggle-btn');\n"\
"      var numpad_btn_icon = document.getElementById('numpad-btn-icon');\n"\
"      var joystick_btn_icon = document.getElementById('joystick-btn-icon');\n"\
"      var numpad_container = document.getElementById('numpad-container');\n"\
"      numpad_joystick2_toggle_btn.onclick = function (e) {\n"\
"        e.preventDefault();\n"\
"        showJoystick2 = !showJoystick2;\n"\
"        numpad_btn_icon.style.display = showJoystick2 ? 'inline' : 'none';\n"\
"        joystickContainer2.style.display = showJoystick2 ? 'inline' : 'none';\n"\
"\n"\
"        joystick_btn_icon.style.display = showJoystick2 ? 'none' : 'inline';\n"\
"        numpad_container.style.display = showJoystick2 ? 'none' : 'inline';\n"\
"      }\n"\
"    </script>\n"\
"</body>\n"\
"\n"\
"</html>\n"\
;
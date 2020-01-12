ESP8266WebServer WebServer(80);

void login() {
  String loginpage = "<!DOCTYPE html><html lang='sv'> <head> <meta charset='utf-8'> <meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'> <meta name='description' content=''> <meta name='author' content='Mark Otto, Jacob Thornton, and Bootstrap contributors'> <meta name='generator' content='Jekyll v3.8.5'> <title>Login-WebServer</title> <link rel='Stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css' integrity='sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS' crossorigin='anonymous'><link href='https://www.epnadata.com/iot18/demo/css/style.css'> <link rel='Stylesheet' href='Stylesheet.css'> </head> <body class='text-center'> <form action='/login'> <metod='post'><form class='form-signin'> <img class='mb-4' src='C:\Users\Felix\OneDrive - System Provider Edenborgh AB\Bilder\Osi-vz-ip-model-sv' alt='' width='72' height='72'> <h1 class='h3 mb-3 font-weight-normal'>Please sign in</h1> <label for='inputEmail' class='sr-only'>Email address</label> <input type='email' name='inputEmail' id='inputEmail' class='form-control' placeholder='Email address' required autofocus> <label for='inputPassword' class='sr-only'>Password</label> <input type='password' name='inputPassword' id='inputPassword' class='form-control' placeholder='Password' required> <div class='checkbox mb-3'> <label> <input type='checkbox' name='inputRememberMe' value='remember-me'> Remember me </label> </div><button class='btn btn-lg btn-primary btn-block' type='submit'>Sign in</button> <p class='mt-5 mb-3 text-muted'>&copy; 2017-2018</p></form></body></html>";
  WebServer.send(200, "text/html", loginpage);
}
void overview(){
  WebServer.send(200, "text/plain", "<h1>Overview</h1>");
}



void validateLogin(){
  if(WebServer.args() > 0){
    for(uint8_t i = 0; i < WebServer.args(); i++){
      if(WebServer.argName(i) == "inputEmail"){
        if(WebServer.arg(i) == "emailaddress"){
          emailCheck = true;
        }
      }
      if(WebServer.argName(i) == "inputPassword"){
        if(WebServer.arg(i) == "user_password"){
          Serial.println("Your password works");
          passwordCheck = true;
        }
      }
    }
  }
  if(emailCheck && passwordCheck){
    WebServer.sendHeader("Location", "/overview");
    WebServer.send(303);
  }else{
    WebServer.sendheader("Location", "/");
    WebServer.send(303);
  }
}

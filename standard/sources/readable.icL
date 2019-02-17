`` the begin of program

`` try to go to mai.ru
if (Tab.get "mai.ru") {
    `` site loaded successfull
    `` click the button
    tag[button].click();
}
else {
    `` try again later
    `` now log the error
    Log.error "The site mai.ru is unaviable";
};

`` end of the program

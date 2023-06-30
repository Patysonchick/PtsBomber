struct service
{
    string name;
    string url;
    string data;
};

service Services[] =
{
    [0] =
    {
        .name   = "Telegram",
        .url    = "https://my.telegram.org/auth/send_password",
        .data   = "phone=+"
    },

    [1] =
    {
        .name   = "My Games",
        .url    = "https://account.my.games/signup_phone_init/",
        .data   = "csrfmiddlewaretoken=B6GwyuwOSpMCrx80eXfOWAAKsqHR3qjBv7UYwkpYprKv7LOJCmfYwvwWVmIHmeRQ&continue=https://account.my.games/profile/userinfo/&lang=ru_RU&adId=0&password=qweasdzxc&method=phone&phone="
    },

    [2] =
    {
        .name   = "Findclone",
        .url    = "https://findclone.ru/register",
        .data   = "phone="
    },

    [3] =
    {
        .name   = "Adengi",
        .url    = "https://adengi.ru/rest/v1/registration/code/send",
        .data   = "email=marchenkoserofim@gmail.com&firstName=Иван&lastName=Иванов&middleName=Иванов&via=sms&phone="
    },

    [4] =
    {
        .name   = "Bandeatos",
        .url    = "https://bandeatos.ru/?MODE=AJAX",
        .data   = "sessid=404d33f8bac1c1aa4305e6af3ebffa8b&FORM_ID=bx_1789522556_form&PHONE_NUMBER=+"
    }
};
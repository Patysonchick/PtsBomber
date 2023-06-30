struct service
{
    string name;
    string url;
    string data;

    bool isException;
};

service Services[] =
{
    /*[0] =
    {
        .name           = "Gosuslugi",
        .url            = "https://www.gosuslugi.ru/auth-provider/mobile/register",
        .data           = "instanceId=123&firstName=Иван&lastNaexceptionme=Иванов&contactType=mobile&contactValue=+",

        .isException    = true
    },*/

    [0] =
    {
        .name           = "Telegram",
        .url            = "https://my.telegram.org/auth/send_password",
        .data           = "phone=+",

        .isException    = false
    },

    [1] =
    {
        .name           = "My Games",
        .url            = "https://account.my.games/signup_phone_init/",
        .data           = "csrfmiddlewaretoken=B6GwyuwOSpMCrx80eXfOWAAKsqHR3qjBv7UYwkpYprKv7LOJCmfYwvwWVmIHmeRQ&continue=https://account.my.games/profile/userinfo/&lang=ru_RU&adId=0&password=qweasdzxc&method=phone&phone=",

        .isException    = false
    },

    [2] =
    {
        .name           = "Findclone",
        .url            = "https://findclone.ru/register",
        .data           = "phone=",

        .isException    = false
    }
};
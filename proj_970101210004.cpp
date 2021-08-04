//ATM made by Nasim faridnia
#include<iostream>
using namespace std;
int main(){
    int depo,dev_bal=130000000;
int with,n50000=200,n100000=200,n500000=200,a,b,c,r,r2;//for withdraw
serial://read serial number
    int  balance=0,srl,pass,i;
    cout<<"\n---------------------------------------------------------------\n\n Welcome!\n\n enter serial number:";
    cin>>srl;
    switch(srl){
case 94527613 :{
    goto password;
    break;

case 61793582:
    goto password;
    break;
case 0 :{
    cout<<"\n have a nice day!";
    return 0;}

    default :{cout<<"\n invalid serial number!"<<endl;
 goto serial;}
    }//serial ends here

password://read password
if(srl==94527613){
    for(i=1;i<=3;i++){//password tries
cout<<"\n enter password(numbers only):";
cin>>pass;
if(pass==6666)
    goto menu;
else
    cout<<"\n wrong password!";}//password tries ends here
cout<<"\n too many tries.Your card will be confiscated.";
goto serial;}//if ends here
else{//for the other serial number
for(i=1;i<=3;i++){
        cout<<"\n enter password(numbers only):";
cin>>pass;
        if(pass==4444)
        goto menu;
else
    cout<<"\n wrong password!";}
    cout<<"\n too many tries.Your card will be confiscated.";
    goto serial;}//else ends here
//password ends

menu:
    int opt;
    cout<<"\n ----------------------------------------------------------\n "<<endl;
    cout<<"\n 1.balance \t 2.deposit \t 3.withdraw \t 4.transfer \t 5.buy charge \t 6.pay bill \t 7.log out";
    cout<<"\n\n choose an option:";
    cin>>opt;
switch(opt){
case 1 :{//balance

    cout<<"\n your balance is:"<<balance;
    goto menu;
break;}//case1 ends


case 2 :{//deposit
deposit:
    cout<<"\n enter the amount you wish to deposit:";
    cin>>depo;
    if(depo==0)
        goto menu;
    if(depo%5==0){
    balance=balance+depo;
    cout<<"\n your new balance is :"<<balance;
    goto menu;}//if ends
    else {
            cout<<"\n invalid amount";
    goto deposit;}//else ends

break;}//case2 ends


case 3 :{//withdraw
    withdraw:

    cout<<"\n\n enter the amount you wish to withdraw:";
    cin>>with;
    if(with==0)//abort
        goto menu;
    if(balance>=with){
            if(with%5==0){
                    if(with<2000000){
                        if(with<=dev_bal){
                            a= with/500000;// number of 500000s
                            if(n500000>=a)//to see if the device has enough 500000s
                               n500000= n500000-a;
                               else {//if not enough 500000
                               r=with;
                               goto B;}
                             r=with%500000;
                             B:
                         b=r/100000;//number of 100000s
                         if(n100000>=b)
                            n100000=n100000-b;
                            else{    //not enough 100000s
                            r2=r;
                            goto C;}
                            r2=r%100000;
                            C:
                         c=r2/50000;//number of 50000s
                         if(n50000>=c)
                            n50000=n50000-c;
                            else{//not enough 50000s
                                cout<<"\n sorry! unable to pay.";
                            goto menu;}
                            cout<<"\n you receive "<<a<<" 500000s\t\t"<<b<<" 100000s\t\t"<<c<<" 50000s";//if device is able to pay
                            balance=balance-with;
                            cout<<"\n\n Your new balance is :"<<balance;
                            goto menu;

                        }//fifth if
                        else{
                                cout<<"\n sorry.device balance is not enough.";
                        goto withdraw;}
                    }//fourth if ends(less than 20000000)
                    else{
                            cout<<"\n the amount must be below 2000000";
                    goto withdraw;}//else ends
            }//third if ends(5)
            else{
                    cout<<"\n invalid amount!";
            goto withdraw;}//second else ends
    }//second if ends(balance>with)
    else{
            cout<<"\n insufficient balance!";
    goto menu;}// third else ends

}//case3 ends(withdraw)

case 4 :{//transfer
    int trns,des_serial;
cout<<"\n enter the amount you wish to transfer:";
cin>>trns;
 cout<<"\n enter the destination serial number:";
    cin>>des_serial;
if((trns%5==0)&&(balance>=trns)&&(trns!=0)){
    balance=balance-trns;
    cout<<"\n transfer done!.Your new balance is:"<<balance;}
    else if(trns==0)
        goto menu;
    else
        cout<<"\n invalid amount or insufficient balance!";
    goto menu;
break;}//case 4 ends

case 5 :{//buy charge
    int chrg;
    cout<<"\n 1.10000 \t 2.20000 \t 3.50000 \t 4.100000"<<endl<<"choose an option:";
    cin>>chrg;
    if ((balance>=chrg)&&chrg!=0){
            balance=balance-chrg;
    cout<<"\n transaction  done!.Your new balance is:"<<balance;
    cout<<"\n your tracking code is:"<<8716942785;}//if ends
    else if(chrg==0)
        goto menu;
    else
        cout<<"\n insufficient balance!";
    goto menu;
break;
}//case5 ends

case 6 :{//pay bill
    int bill_id;
    int bill;
    cout<<"\n enter bill ID:";
    cin>>bill_id;
    if(bill_id==0)
        goto menu;
    cout<<"\n enter the amount you want to pay:";
    cin>>bill;
    if(balance>=bill){
            balance=balance-bill;
    cout<<"\n transaction done!your new balance is:"<<balance;
    cout<<"\n your tracking code is:"<<128749;}//if ends
    else
            cout<<"\n your balance is insufficient!";
            goto menu;
            break;
}//case6 ends

case 7 :{//log out
    cout<<"\n thank you.You may take your card.have a good day!";
    goto serial;
    break;}//case7 ends
;}//switch(opt)ends here
return 0;
}}

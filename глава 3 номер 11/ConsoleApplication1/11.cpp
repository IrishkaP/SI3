#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
     int one_c, five_c, ten_c, twentyfive_c, fifty_c, dollar, itog;
     cin >> one_c >> five_c >> ten_c >> twentyfive_c >> fifty_c >> dollar;
     cout << "У вас: " << endl;
     if (dollar != 0)
         switch (dollar % 10) {
         case 1: {
             cout << dollar << " долларовая монета" << endl;break;}
         case 2: case 3: case 4:{
             cout << dollar << " долларовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << dollar << " долларовых монет" << endl;break;
         }
     }
     if (fifty_c != 0)
         switch (fifty_c % 10) {
         case 1:{
             cout << fifty_c << " 50-центовая монета" << endl;break;
         }
         case 2: case 3: case 4:{
             cout << fifty_c << " 50-центовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << fifty_c << " 50-центовых монет" << endl;break;
         }
     }
     if (twentyfive_c != 0)
         switch (twentyfive_c % 10) {
         case 1:{
             cout << twentyfive_c << " 25-центовая монета" << endl;break;
         }
         case 2: case 3: case 4:{
             cout << twentyfive_c << " 25-центовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << twentyfive_c << " 25-центовых монет" << endl;break;
         }
     }
     if (ten_c != 0)
         switch (ten_c % 10) {
         case 1:{
             cout << ten_c << " десятицентовая монета" << endl;break;
         }
         case 2: case 3: case 4:{
             cout << ten_c << " десятицентовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << ten_c << " десятицентовыхх монет" << endl;break;
         }
     }
     if (five_c != 0)
         switch (five_c % 10) {
         case 1:{
             cout << five_c << " пятицентовая монета" << endl;break;
         }
         case 2: case 3: case 4:{
             cout << five_c << " пятицентовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << five_c << " пятицентовых монет" << endl;break;
         }
     }
     if (one_c != 0)
         switch (one_c % 10) {
         case 1:{
             cout << one_c << " одноцентовая монета" << endl;break;
         }
         case 2: case 3: case 4:{
             cout << one_c << " одноцентовые монеты" << endl;break;
         }
         case 5: case 6: case 7: case 8: case 9: case 0:{
             cout << one_c << " одноцентовых монет" << endl;break;
         }
     }
     itog = one_c + (five_c * 5) + (ten_c * 10) + (twentyfive_c * 25) + (fifty_c * 50) + (dollar * 100);
     cout << "Всего " << itog << " центов ( " <<itog / 100.0 << "$)";
    return 0;
}
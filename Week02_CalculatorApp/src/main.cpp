#include<iostream>
#include<string.h>
using namespace std;
class Complex{
    private:
        float real, img;
    public:
        void input(){
            cout<<"Real Part: ";
            cin>>real;
            cout<<"Imaginary Part: ";
            cin>>img;
        }
        Complex operator+(Complex C1){
            Complex C;
            C.real = real+ C1.real;
            C.img = img + C1.img;
            return C;
        }
        Complex operator-(Complex C1)
        {
            Complex C;
            C.real = real- C1.real;
            C.img = img - C1.img;
            return C; 
        }
        Complex operator*(Complex C1)
        {
            Complex C;
            C.real = real*C1.real-img*C1.img;
            C.img = real * C1.img + C1.real*img;
            return C; 
        }
        Complex operator/(Complex C1)
        {
            Complex C;
            float denom = C1.real * C1.real + C1.img * C1.img;
            C.real = (real * C1.real + img * C1.img) / denom;
            C.img  = (img * C1.real - real * C1.img) / denom;
            return C;
        }
        void display_complex(){
            cout<<real<<" + "<< "( "<<img<< "i )"<<endl;
        }

};
class String{
    private:
        string str;
    public:
        void input(){
            cin>>str;
        }
        String operator+(String S1){
            String S;
            S.str = str.append(S1.str);
            return S;
        }
        void display_string(){
            cout<<"Addition = "<<str<<endl;
        }
};
template <typename T>
class Calculator{
    private:
        T num1, num2, res;
    public:
        Calculator(T a, T b)
        {
            num1 = a;
            num2= b;
        }
        T add(){
            return num1+num2;
        }
        T sub(){
            return num1-num2;
        }
        T mul()
        {
            return num1*num2;
        }
        T div(){
            return (float)num1/num2;
        }
};
template <typename T>
void display(T sum, T sub,T mul,T div){
    int choice;
    cout<<"Eneter your choise\n[For Addition Enter 1 \t For Subtraction Enter 2 \t For Multiplication Enter 3 \t For Division Enter 4]:";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Addtion= "<<sum<<endl;
            break;
        case 2:
            cout<<"Difference = "<<sub<<endl;
            break;
        case 3:
            cout<<"Multiplication = "<<mul<<endl;
            break;
        case 4:
            cout<<"Division = "<<div<<endl;
            break;
        default:
            cout<<"You Entered Wrong choice.";
            
    }
}
int main(){
    string want, buffer;
    do{
    cout<<"-----------------CALCULATOR--------------------"<<endl;
    string enter;
    cout<<"\n1. Integer Calculator, \n2. Floating Calculator \n3. Complex Calculator \n4. String Calculator\nEnter Which Types of Calculator You Wants.:"<<endl;
    getline(cin, enter);
    if(enter=="integer" || enter =="Integer"|| enter=="INTEGER"|| enter== "1"|| enter=="INTEGER CALCULATOR"|| enter=="Integer Calculator", enter=="integer calculator"){
     int a1, b1,sum,sub, mul;
    float div;
    cout<<"Enter the First Number: ";
    cin>> a1;
    cout<<"Enter the First Number: ";
    cin>> b1;
    Calculator<int> c(a1, b1);
    sum=c.add();
    sub= c.sub();
    mul= c.mul();
    div = c. div();
    display<int>(sum,sub,mul,div);
    }
    else if(enter=="float" || enter=="Float"||enter=="FLOAT", enter== "2"|| enter=="Floating"|| enter=="Floating Calculator"){
    float  a1, b1,sum,sub, mul;
    float div;
    cout<<"Enter the First Number: ";
    cin>> a1;
    cout<<"Enter the First Number: ";
    cin>> b1;
    Calculator<float> c(a1, b1);
    sum=c.add();
    sub= c.sub();
    mul= c.mul();
    div = c. div();
    display<float>(sum,sub, mul, div);
    }
    else if(enter == "Complex"|| enter == "complex"|| enter == "COMPLEX"|| enter == "3"|| enter =="Complex Calculator"){
        Complex C2, C3, sum, sub, mul, div;
        cout<<"Enter First Complex Number"<<endl;
        C2.input();
        cout<<"Enter First Complex Number"<<endl;
        C3.input();
        sum= C2+(C3);
        sub=C2-(C3);
        mul=C2*(C3);
        div=C2/(C3);
        int choice;
       cout<<"Eneter your choise\n[For Addition Enter 1 \t For Subtraction Enter 2 \t For Multiplication Enter 3 \t For Division Enter 4]:";
       cin>>choice;
       switch(choice){
            case 1:
                cout << "Addition = ";
                sum.display_complex();
                break;

            case 2:
                cout << "Difference = ";
                sub.display_complex();
                break;

            case 3:
                cout << "Multiplication = ";
                mul.display_complex();
                break;

            case 4:
                cout << "Division = ";
                div.display_complex();
                break;

            default:
            cout << "You Entered Wrong choice.";
        }
    }
    else if(enter == "String"|| enter == "string"|| enter == "STRING"|| enter == "4"|| enter =="StringCalculator"){
       String S2, S3,S4;
       cout<<"String Addition Only Possible "<<endl;
       cout<<"Enter First String: ";
       S2.input();
       cout<<"Enter Second String: ";
       S3.input();
       S4= S2+S3;
       S4.display_string();
    }
    else{
        cout<<"Wrong Chooise."<<endl;
    }
    getline(cin,buffer);
    cout << "Would you like to Continue (Y/N)?" << endl;
    getline(cin, want);

    }while(want=="y" || want == "Y" ||want=="Yes"||want=="yes"||want=="YES");

}
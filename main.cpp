#include "header.h"

int main() {
    std::vector <std::string> op = {"+","-","*","/","^","(",")"};
    std::string vhod,vihod;
    std::cout << "Введите выражение:";
    std::getline(std::cin,vhod);
    edit_string(vhod,op);
    std::vector<std::string> vec = pars(vhod);
    replace_un_minus(vec,op);
    bool check = is_correct(vec);
    if (!check) {
        std::cout << "ОШИБКА!" << '\n';
        return 1;
    }
    std::stack<std::string> st;
    for (auto m: vec) {     //постфиксная запись
        if (is_numb(m) || m=="x") {
            vihod+=m;
            vihod+=' ';
        }
        else if (m=="(") {
            st.push(m);
        }
        else if (is_func(m)) {
            st.push(m);
        }
        else if (m==")" && !st.empty()) {
            while (st.top()!="(") {
                vihod+=st.top();
                vihod+=' ';
                st.pop();
            }
            st.pop();
        }
        else if (is_operator(m)) {
            if (!st.empty()) {
                if (is_func(st.top())) {
                    vihod+=st.top();
                    vihod+=' ';
                    st.pop();
                }
                if (!st.empty()&&pr_comparing(st.top()[0],m[0])&&st.top()!="(") {
                    vihod+=st.top();
                    vihod+=' ';
                    st.pop();
                }
            }
            st.push(m);
        }
    }
    while (!st.empty()) {
        vihod+=st.top();
        vihod+=' ';
        st.pop();
    }       //vihod содержит постфиксную запись
   // std::cout<<vihod<<'\n';
    std::vector <std::string> calc;
    if (vihod.find('x',0) != std::string::npos) {
        std::cout << "Введите значение переменной x:";
        std::string x;
        std::cin>>x;
        if (is_numb(x)) {
            calc=repl_x(vihod,x); //cплит постфиксной записи по пробелу
        }                           //и запись вместо x вводимого значения
        else {
            std::cout << "Ошибка" << '\n';
            return 1;
        }
    }
    else {
        calc = pars(vihod);
    }                               //расчёт
    double a,b;
    for (int i = 0; i < calc.size();i++) {
        if (is_numb(calc[i])) {
            if (calc[i]=="π") {
                st.push("3.14");
            }
            else{st.push(calc[i]);}
        }
        else if (is_operator(calc[i]) && st.size()>=2) {
            a = std::stof(st.top());
            st.pop();
            b = std::stof(st.top());
            st.pop();
            if (calc[i]=="+") {
                st.push(std::to_string(b+a));
            }
            else if (calc[i]=="-") {
                st.push(std::to_string(b-a));
            }
            else if (calc[i]=="^") {
                st.push(std::to_string(pow(b,a)));
            }
            else if (calc[i]=="/") {
                st.push(std::to_string(b/a));
            }
            else if (calc[i]=="*") {
                st.push(std::to_string(b*a));
            }
        }
        else if (is_func(calc[i]) && !st.empty()) {
            a = std::stof(st.top());
            st.pop();
            if (calc[i]=="neg") {
                st.push(std::to_string(-a));
            }
            else if (calc[i]=="sin") {
                st.push(std::to_string(sin(a)));
            }
            else if (calc[i]=="cos") {
                st.push(std::to_string(cos(a)));
            }
            else if (calc[i]=="tg") {
                st.push(std::to_string(tan(a)));
            }
            else if (calc[i]=="ctg") {
                st.push(std::to_string(1/tan(a)));
            }
            else if (calc[i]=="exp") {
                st.push(std::to_string(exp(a)));
            }
        }
    }
    std::cout << "Результат: "<<st.top();
}
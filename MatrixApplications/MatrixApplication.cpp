#include<iostream>
using namespace std;

#define s 20

class matrix
{
private:
    int a[s][s];
    int row;
    int col;
public:
    void input();
    void output();
    matrix operator+(matrix);
    matrix operator-(matrix);
    matrix operator*(matrix);
};

void matrix::input(){
    cout<<"Enter the order of Matrix "<<" :\n";
    cin>>row>>col;
    cout<<"Enter the Matrix "<< " :\n";
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cin>>a[i][j];
        }
    }
}

void matrix::output(){
    cout<<"The ans is :\n";
    for(int i =0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

matrix matrix::operator+(matrix b){
    matrix r;
    if((row!=b.row)||(col!=b.col)){
        cout<<"\n\tMatrix Addition is not possible the result is incorrect\n\n";
        r.row = 0;
        r.col = 0;
    }
    else{
        r.row = row;
        r.col = col;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            r.a[i][j] = a[i][j] + b.a[i][j];
        }
    }
    return r;
}

matrix matrix::operator-(matrix b){
    matrix r;
    if((row!=b.row)||(col!=b.col)){
        cout<<"\n\tMatrix Subtraction is not possible the result is incorrect\n\n";
        r.row = 0;
        r.col = 0;
    }
    else{
        r.row = row;
        r.col = col;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            r.a[i][j] = a[i][j] - b.a[i][j];
        }
    }
    return r;
}

matrix matrix::operator*(matrix b){
    matrix r;
    if((row!=b.row)||(col!=b.col)){
        cout<<"\n\tMatrix multiplication is not possible the result is incorrect\n\n";
        r.row = 0;
        r.col = 0;
    }
    else{
        r.row = row;
        r.col = col;
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            r.a[i][j] = 0;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            for(int k = 0; (k<col||k<b.row);k++)
                r.a[i][j] += a[i][j]* b.a[i][j];
        }
    }
    return r;
}

int main(){
    int option;
    matrix a,b,c;
    do{

        cout<<"\nSelect Option\n"
        <<"0.Exit\n"
        <<"1.Matrix Addition\n"
        <<"2.Matrix Subtraction\n"
        <<"3.Matrix Multiplication\n"
        <<"4.Clear Screen\n\n";

        cin>>option;

        switch(option){
        case 0:
            break;

        case 1:
            cout<<"\n\nMatrix Addition\n\n";
            a.input();
            b.input();
            c = a + b;
            c.output();
            break;

        case 2:
            cout<<"\n\nMatrix Subtraction\n\n";
            a.input();
            b.input();
            c = a - b;
            c.output();
            break;

        case 3:
            cout<<"\n\nMatrix Multiplication\n\n";
            a.input();
            b.input();
            c = a*b;
            c.output();
            break;

        case 4:
            system("cls");
            break;

        default:
            cout<<"\nInvalid Input\n";
        }

    }while(option!=0);

    return 0;
}


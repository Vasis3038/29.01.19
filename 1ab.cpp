# 29.01.19#include <iostream>

using namespace std;

class double_vector
{
private:
double *vec;
unsigned int N;
unsigned int cap;
    public:

    double_vector()//конструктор без аргументов 
    {
        cap=2;
        N=1;
       this-> vec = new double [N];
        vec[0]=0;
    }
    double_vector(double *A, int N)//конструктор создающий вектор по double-массиву и его размеру

    {
        cap=N;
        this-> N = N;
        this-> vec = new double[N];
        for(int i=0; i<N; i++) vec[i]=A[i];

    }

    double_vector(int N)//конструктор с одним аргументом - длинной массива
    {
        cap=N;
        this-> N = N;
        this-> vec = new double[N];
        for(int i=0; i<N; i++) vec[i]=0;
    }

        double_vector(const double_vector& A)//конструктор копий
    {
        this-> cap=A.cap;
        this-> vec=new double[A.N];
        for(int i=0; i<A.N; i++) this-> vec[i]=A.vec[i];
    }

    const double_vector& operator=(const double_vector& A)//оператор присвоения
    {
        this-> cap=A.cap;
        this->N=A.N;
        delete []this->vec;

        this-> vec=new double[A.N];
        for(int i=0; i<A.N; i++) this-> vec[i]=A.vec[i];
        return *this;
    }
        double& operator[] (unsigned int n)//оператор обращения по индексу
    {
        return vec[n];
    }

    void push_back(double x)//добавление в конец
    {
        if(N>=cap)
        {
            cap*=2;
            double *temp=new double[cap];
            for(int i=0; i<N; i++) temp[i]=vec[i];
            delete []vec;
            vec = temp;

        }
        vec[N]=x;
        N++;
    }
        double pop_back()//извлечение из конца
    {
       if(N!=0)
       {
            double tempp=vec[N-1];
            N--;
            cap--;
            double *temp=new double[cap];
            for(int i=0; i<N; i++) temp[i]=vec[i];
            delete []vec;
            vec=temp;
            return tempp;
       }
       else  return 0;

    }
      unsigned int size() //получение размера вектора
    {
        return N;
    }
    unsigned int capacity()//получение вместимости вектора
    {
        return cap;
    }

    void resize(int x)//изменение вместимости массива
    {
        if (x>=N)
        {
            cap=x;
        }
        else cout<<"too small"<<endl;
    }
    void push_front(double x)//добавление в начало
    {

        if(N>=cap)
        {
            cap*=2;
        }
            double *temp=new double[cap];
            temp[0]=x;
            for(int i=0; i<N; i++) temp[i+1]=vec[i];
            delete []vec;
            vec = temp;
        N++;
    }
    void pop_front()//удаление из начала
    {
         if(N!=0)
       {
            double tempp=vec[N-1];
            N--;
            cap--;
            double *temp=new double[cap];
            for(int i=0; i<N; i++) temp[i]=vec[i+1];
            delete []vec;
            vec=temp;
       }
       else cout<<"there are no elements in the array"<<endl;
    }

    void insert(int x, int num)//добавление на заданную позицию
    {
    if (cap+1<=N)
    {
        cap*=2;
    }

    for(int i = N; i>=num; i--) vec[i]=vec[i-1];
    vec[num-1]=x;
    N++;
    }

    void erase(int pos)//удаление из заданной позиции 
    {
    for(int i = pos; i<N-1; i++) vec[i]=vec[i+1];
    N--;
    }

    void erase(int a, int b)//удаление интервала по индексам концов отрезка
    {
        while((cap-(b-a+1))<=N) cap++;
            cap=cap-(b-a+1);

            double *temp=new double[cap];
            int g=a;
            for(int i=0; i<a; i++) {temp[i]=vec[i];}

            for(int i=b+1; i<N; i++){temp[g]=vec[i];g++;}
            delete []vec;
            N=N-(b-a+1);
            vec=temp;
    }
    void find(double x)//линейный поиск по массиву методом
    {
        bool red=0;
        int i=0;

        while(red!=1 && i<N)
        {

            if(vec[i]==x ){cout<<"attend, number is "<<i<<endl; red=1;}
            i++;
        }
        if (red==0)cout<<"missing"<<endl;
    }

    operator + (double_vector &A)//конкатенация(слияние) векторов operator+
    {
            this-> cap=A.cap+this->cap;
            double *temp=new double[this-> cap];
            int g=0;
            for(int i=0; i<this->N; i++) {temp[i]=vec[i];}
            for(int i=N; i<this->N+A.N; i++){temp[i]=A[g];g++;}
            delete []vec;

            this->N=this->N+A.N;
            vec = temp;

    }
    ~double_vector()//деструктор
    {
        delete[] vec;
    }

};
int main()
{
    return 0;
}

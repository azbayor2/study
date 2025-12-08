#include <iostream>
#include <queue>
#include <random>

using namespace std;

class washer{
    private:
    int wash_time;
    int left_time;

    public:
    bool is_busy(){
        return left_time>0;
    }

    void start(){
        left_time = wash_time;
    }

    void one_second(){
        left_time--;
    }

    washer(int init_time=60){
        wash_time = init_time;
        left_time = 0;
    }
};

class bool_source{
    private:
    double prob;

    public:
    bool_source(double init_val=0.5){
        prob = init_val;
    }

    bool new_source(){
        return rand()>RAND_MAX*prob;
    }
};

class statistic{
    private:
    double total_time;
    int num;

    public:
    statistic(){
        total_time=0;
        num = 0;
    }

    void add(double time){
        num++;
        total_time+=time;
    }

    void show_statictic(){
        cout << "total car washed: " << num << endl;
        cout << "average time: " << (double)total_time/num << endl;
    }
};

void car_wash(int init_time, double prob, int sim_time){
    washer w(init_time);
    bool_source b(prob);
    statistic st;
    queue<int> q;

    for(int i =0; i<sim_time; i++){
        if(b.new_source()) q.push(i);
        if(!w.is_busy() && q.size()){
            st.add(i-q.front());
            w.start();
            q.pop();
        }
        w.one_second();
    }

    st.show_statictic();

    return;
}


int main(){
    car_wash(60, 0.5, 1000);
    return 0;
}
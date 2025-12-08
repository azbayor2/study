#include <iostream>
#include <queue>
#include <random>

using namespace std;

class washer{
    private:

    int left_time;
    int time_for_wash;

    public:
    washer(int t=60){
        time_for_wash = t;
        left_time=0;
    };

    bool busy(){
        return left_time>0;
    }

    void one_second(){
        if(busy())
            left_time--;
    };

    void start_washing(){
        if(busy()) return;

        left_time = time_for_wash;
    };

};

class bool_source{
    private:
    double prob;

    public:
    bool_source(double p=0.5){
        prob = p;
    };

    bool query() const{
        return (rand() < prob*RAND_MAX);
    }
};

class averager{
    private:
    size_t count;
    double sum;

    public:
    averager(){
        count=0;
        sum = 0;
    };

    void next_number(double value){
        sum+=value;
        count++;
    }

    size_t how_many_numbers() const{
        return  count;
    }

    double average() const{
        return sum/count;
    }
};

void car_wash_simulation(int washtime, double prob, int sim_time){
    washer w(washtime);
    bool_source src(prob);
    averager avg;
    queue<int> q;

    for(int i =0; i<sim_time; i++){
        if(src.query())
            q.push(i);

        if(!w.busy() && q.size()){
            w.start_washing();
            avg.next_number(i-q.front());
            q.pop();
        }

        w.one_second();
    }

    cout << "Total car washed: " << avg.how_many_numbers() << endl;
    cout << "average wait time: " << avg.average() << endl;

    return;
};


int main(){
    car_wash_simulation(60, 0.5, 1000);

    return 0;
}
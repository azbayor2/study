#include <iostream>
#include <queue>
#include <random>

using namespace std;

class washer{
    private:
    int default_time;
    int left_time;
    bool busy;
    public:
        washer(int default_time){
            this->default_time = default_time;
            left_time = 0;
        };

        void start(){
            busy=true;
            left_time = default_time;
        };

        bool isbusy(){
            return busy;
        };

        void tickingtime(){
            left_time--;
            if(left_time==0){
                busy=0;
            }
        };
};

class bool_source{
    private:
    double probability;
    public:
    bool_source(double p=0.5){
        probability = p;
    };

    bool query() const{
        return (rand()<probability*RAND_MAX);
    }
};

class averager{
    private:
    double sum;
    int count;

    public:
    double get_avg() const{
        return (double)sum/count;
    };

    double get_num() const{
        return count;
    };

    void add_data(double ttime){
        count++;
        sum+=ttime;
    };

    averager(){
        sum = 0; count = 0;
    };
};


void start(){
    cout << "enter total time and prob and def_time: ";
    int time, wash_time; double prob;

    cin >> time >> prob >> wash_time;

    queue<int> q;

    washer w(wash_time);
    averager a;
    bool_source b(prob);

    for(int i =0; i<time; i++){
        if(b.query()){
            q.push(i);
        }

        if(!w.isbusy() && q.size()){
            a.add_data(time-q.front());
            q.pop();
            w.start();
        }

        w.tickingtime();

    }

    cout << a.get_avg() << endl;

    return;
}

int main(){
    start();
    return 0;
}


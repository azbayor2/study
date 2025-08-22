#include <iostream>
using namespace std;
typedef pair<int, int> p;
int N, M, arr[501][501], ans;

typedef struct {
    p coords[4];
} Shape;  //4개의 좌표를 저장하는 도형

p rotate_coord(p pp){   //좌표 회전 (반시계방향)
    return {pp.second, pp.first*(-1)};
}

p invert_coord(p pp){  // 좌표 반전 (세로축 기준)
    return {-pp.first, pp.second};
}

Shape shape[5] = {
    {{{0,0},{1,0},{2,0},{1,1}}}, //ㅗ
    {{{0,0},{1,0},{2,0},{3,0}}},  // ㅡ 
    {{{0,0},{1,0},{0,1},{1,1}}}, // ㅁ 
    {{{0,0},{1,0},{2,0},{2,1}}}, // ㄱ
    {{{0,0},{1,1},{1,0},{2,1}}}  //z 
}; //5개의 기본 도형을 저장
                  
Shape rotate(Shape s){   //도형 회전
    Shape new_shape;
    for(int i =0; i<4; i++)
        new_shape.coords[i] = rotate_coord(s.coords[i]);
    return new_shape;
}

Shape invert(Shape s){   //도형 반전
    Shape new_shape;
    for(int i=0; i<4; i++)
        new_shape.coords[i] = invert_coord(s.coords[i]);
    return new_shape;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
            
    for(int k=0; k<5; k++){
        Shape temp = shape[k];  //기본 도형 선택
        for(int l=0; l<4; l++){
            temp = rotate(temp);  //회전 
            for(int m=0; m<2; m++){
                temp = invert(temp);  //좌우반전
                for(int i =0; i<N; i++)
                    for(int j =0; j<M; j++){
                        Shape apply_shape;
                        bool flag=0; int summ=0;
                        for(int n=0; n<4; n++){
                            apply_shape.coords[n] = {j+temp.coords[n].first, i+temp.coords[n].second};
                            if(apply_shape.coords[n].first<0 || apply_shape.coords[n].first>=M) flag=1;
                            if(apply_shape.coords[n].second<0 || apply_shape.coords[n].second>=N) flag=1;
                            if(flag==1) break; //만약 벗어난 좌표가 있으면
                            summ+=arr[apply_shape.coords[n].second][apply_shape.coords[n].first];
                        }
                        if(flag==1) continue;
                        ans = max(ans, summ);
                    }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

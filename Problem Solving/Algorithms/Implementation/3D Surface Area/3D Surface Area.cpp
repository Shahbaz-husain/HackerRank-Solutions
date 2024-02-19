#include <iostream>
#include <vector>

using namespace std;

int price(vector<vector<int>> faces)
{
    int surface_area = 0;
    int h = faces.size(), w = faces[0].size();
    
    // Taking a temp memory so that we can initiate firts and last row and columns with 0 as references to calculate surface areas of the actual toy cubes
    
    // Given Cube Heights
    // 1 3 4
    // 2 2 3
    // 1 2 4

    // Converting it to
    // 0 0 0 0 0
    // 0 1 3 4 0
    // 0 2 2 3 0
    // 0 1 2 4 0
    // 0 0 0 0 0
    
    // Doing this we can ignore the repeated surface area common between two cubes , for example 1 and 3 have common wall
    vector<vector<int>> temp(h + 2, vector<int>(w + 2 , 0));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            temp[i+1][j+1] = faces[i][j];
        }
    }
    
    // initiaing first surface_area equals to surface areas of top and bottom faces as they will alwyas be common irrespective of the size of the toy cubes
    surface_area = 2 * (w*h);
    
    // Calculating surface areas on a
    for(int i = 1; i < h+1 ; i++)
    {
        for(int j = 1; j < w+1 ; j++)
        {
            if(temp[i][j] > temp[i-1][j])
                surface_area += (temp[i][j] - temp[i-1][j]);
            
            if(temp[i][j] > temp[i+1][j])
                surface_area += (temp[i][j] - temp[i+1][j]);
            
            if(temp[i][j] > temp[i][j+1])
                surface_area += (temp[i][j] - temp[i][j+1]);
                
            if(temp[i][j] > temp[i][j-1])
                surface_area += (temp[i][j] - temp[i][j-1]);
        }
    }
    return surface_area;
}

int main()
{
    int H, W;
    cin >> H >> W;
    
    vector<vector<int>> faces(H, vector<int>(W));
    
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cin >> faces[i][j];
        }
    }
    
    cout << price(faces) << endl;
}
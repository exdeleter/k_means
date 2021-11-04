#include<iostream>
#include<conio.h>
#include <vector>
using namespace std;

void onemeasure()
{
    int i1, i2, i3, t1, t2;

    int k0[10]; 
    int k1[10];
    int k2[10];

    std::cout << "\nEnter 10 numbers:\n";
    for (i1 = 0; i1 < 10; i1++)
    {
        cin >> k0[i1];
    }


    //initial means
    int m1;
    int m2;

    std::cout << "\n Enter initial mean 1:";
    cin >> m1;
    std::cout << "\n Enter initial mean 2:";
    cin >> m2;

    int om1, om2;    //old means

    do
    {

        //saving old means
        om1 = m1;
        om2 = m2;

        //creating clusters
        i1 = i2 = i3 = 0;
        for (i1 = 0; i1 < 10; i1++)
        {
            //calculating distance to means
            t1 = k0[i1] - m1;
            if (t1 < 0)
            {
                t1 = -t1;
            }

            t2 = k0[i1] - m2;
            if (t2 < 0)
            {
                t2 = -t2;
            }

            if (t1 < t2)
            {
                //near to first mean
                k1[i2] = k0[i1];
                i2++;
            }
            else
            {
                //near to second mean
                k2[i3] = k0[i1];
                i3++;
            }

        }

        t2 = 0;
        //calculating new mean
        for (t1 = 0; t1 < i2; t1++)
        {
            t2 = t2 + k1[t1];
        }
        m1 = t2 / i2;

        t2 = 0;
        for (t1 = 0; t1 < i3; t1++)
        {
            t2 = t2 + k2[t1];
        }
        m2 = t2 / i3;

        //printing clusters
        std::cout << "\nCluster 1:";
        for (t1 = 0; t1 < i2; t1++)
        {
            std::cout << k1[t1] << " ";
        }
        std::cout << "\nm1=" << m1;

        std::cout << "\nCluster 2:";
        for (t1 = 0; t1 < i3; t1++)
        {
            std::cout << k2[t1] << " ";
        }
        std::cout << "\nm2=" << m2;

        std::cout << "\n ----";
    } while (m1 != om1 && m2 != om2);

    std::cout << "\n Clusters created";
}
struct Point
{
    double x;
    double y;
};
void Random_Value_Vector(vector<Point>& points,int  amount)
{
    srand(time(NULL));
    for (int i = 0; i < amount; i++)
    {
        Point temp;
        temp.x = (rand() % 1001) / 1000.0;
        temp.y = (rand() % 1001) / 1000.0;
        points[i] =temp;
    }
}
void Out_Point_Vector(vector<Point>& points, int size)
{
    std::cout << endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i << ":" << "(" << points[i].x << "," << points[i].y << ")" << endl;

    }
}
void Copy(vector<Point> FromV, vector<Point>& ToV)
{
    for (int i = 0; i < FromV.size(); i++)
        ToV[i] = FromV[i];

}
double Measure_distance(Point firstpoint, Point secondpoint)
{
    return sqrt(abs(firstpoint.x - secondpoint.x) * abs(firstpoint.x - secondpoint.x) 
        + abs(firstpoint.y - secondpoint.y) * abs(firstpoint.y - secondpoint.y));
}
void Print_clusters_vectors(vector<vector<Point>> clusters, int count_clusters)
{
    for (int i = 0; i < count_clusters; i++)
    {
        cout <<"\nCluster " << i << ": ";
        for (int j = 0; j < clusters[i].size(); j++)
        {
            std::cout << " (" << clusters[i][j].x << "," << clusters[i][j].y << ")" << "| ";
        }
        cout << endl;
    }
}
bool flagequal_vector(vector<Point> oldmean, vector<Point> mean)
{
    for (int i = 0; i < oldmean.size(); i++)
        if (oldmean[i].x - mean[i].x <= 0.0001 && oldmean[i].y - mean[i].y <= 0.0001)
            return false;
    return true;
}
void k_means_2x_with_vector()
{
    std::cout << "Enter amount of point\n";
    int amount;
    cin >> amount;
    std::vector<Point> points(amount); // create point for clusterization
    Random_Value_Vector(points, amount); // fill it random values
    Out_Point_Vector(points, amount); // out it
    cout << "\nEnter count of clusters: ";
    int count_clasters;
    cin >> count_clasters;
    std::vector <vector<Point>> clusters(count_clasters); // create cluster's that need for write it's points
    vector<Point> mean_value(count_clasters); 
    Random_Value_Vector(mean_value, count_clasters); // fill it
    cout << "\nCentral mean: ";
    Out_Point_Vector(mean_value, count_clasters); // out it
    vector<Point> old_mean_value(count_clasters); // create old mean_cluster for compare. need us later
    do
    {
        vector<double> distance(count_clasters);
        Copy(mean_value, old_mean_value);
        for (int i = 0; i < amount; i++) //loop for measure distance between points and clusters
        {
            
            for (int j = 0; j < count_clasters; j++) // loop for measure distance between current point and mean cluster
            {

                distance[j] = Measure_distance(points[i],mean_value[j]);
            }
            int temp = 0; // temp for undertanding between which cluster and point min distance
            double min = distance[0];
            for (int j = 0; j < count_clasters; j++) // find min between points
            {
                if (min > distance[j])
                {
                    min = distance[j];
                    temp = j;
                }
            }
            clusters[temp].push_back(points[i]); // add point in clusters
            Print_clusters_vectors(clusters, count_clasters); //out 

        }

    } while (flagequal_vector(mean_value, old_mean_value));
}
void main()
{
    k_means_2x_with_vector();
}

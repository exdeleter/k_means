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
void k_means()
{
    int i1, i2, i3, t1, t2;
    std::cout << "Enter amount of point\n";
    int amount;
    cin >> amount;
    //std::cout << "Enter the num of clusters\n";
    //int cl_amount;
    //cin >> cl_amount;
    double* startdata = new double[amount];
    double* firstcl = new double[amount];
    double* secondcl = new double[amount];
    std::cout << "\nEnter " << amount << " numbers:\n";
    for (i1 = 0; i1 < amount; i1++)
    {
        std::cout << "point[" << i1 << "]: ";
        cin >> startdata[i1];
    }
    double m1, m2;
    std::cout << "\n Enter first meal:";
    cin >> m1;
    std::cout << "\n Enter second mean:";
    cin >> m2;
    double om1, om2;
    do
    {
        om1 = m1;
        om2 = m2;
        i1 = i2 = i3 = 0;
        for (i1 = 0; i1< amount; i1++)
        {
            t1 = startdata[i1] - m1;
            if (t1 < 0) {
                t1 *= -1;
            }
            t2 = startdata[i1] - m2;
            if (t2 < 0) {
                t2 *= -1;
            }
            if (t1 < t2)
            {
                firstcl[i2] = startdata[i1];
                i2++;
            }
            else
            {
                secondcl[i3] = startdata[i1];
                i3++;
            }

        }
        t2 = 0;
        for (t1 = 0; t1 < i2; t1++)
        {
            t2 += firstcl[t1];
        }
        m1 = t2 / i2;
        t2 = 0;
        for (t1 = 0; t1 < i3; t1++)
        {
            t2 += secondcl[t1];
        }
        m2 = t2 / i3;
        std::cout << "\nCluster 1:";
        for (t1 = 0; t1 < i2; t1++)
        {
            std::cout << firstcl[t1] << " ";
        }
        std::cout << "\nm1=" << m1;

        std::cout << "\nCluster 2:";
        for (t1 = 0; t1 < i3; t1++)
        {
            std::cout << secondcl[t1] << " ";
        }
        std::cout << "\nm2=" << m2;

        std::cout << "\n ----";

    } while (m1 != om1 && m2 != om2);
        
        
}
void OutPoint(Point p[], int size)
{
    std::cout << endl;
    for (int i = 0; i < size ; i++)
    {
        std::cout << i << ":" << "(" << p[i].x
            << "," << p[i].y << ")" << endl;

    }
}
void Copy(Point ToCopy[], Point FromCopy[], int size)
{
    for (int i = 0; i < size; i++)
    {
        ToCopy[i] = FromCopy[i];
    }
}
double Measure_dist(Point First, Point Second)
{
    return sqrt(abs(First.x - Second.x) * abs(First.x - Second.x) + abs(First.y - Second.y) * abs(First.y - Second.y));
}
void Random_Value(Point * points,int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        points[i].x = (rand() % 1001) / 1000.0;
        points[i].y = (rand() % 1001) / 1000.0;
    }
}
void Print_clusters(Point** clasters, int *counter, int count_claster)
{
    for (int i = 0; i < count_claster; i++)
    {
        cout << "\n" << i << " Cluster : ";
        for (int j = 0; j < counter[i]; j++)
        {
            cout << "(" << clasters[i][j].x << "," << clasters[i][j].y << ")" << " |";
        }
        cout << endl;
    }
}
bool flagequal(Point* oldmean, Point* newmean, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (oldmean[i].x != newmean[i].x && oldmean[i].y != newmean[i].y)
            return false;
    }
    return true;
}

void k_means_2x()
{
    int i1, i2, i3, t1, t2;
    std::cout << "Enter amount of point\n";
    int amount;
    cin >> amount;
    Point* points= new Point[amount];

    Random_Value(points, amount);

    OutPoint(points, amount);

    std::cout << "\nEnter count of clasters:";
    int count_clasters;
    cin >> count_clasters;
    Point** clasters = new Point *[count_clasters]; // создается двумерный массив, в котором массивы с кластерами
    for (int i = 0; i < count_clasters; i++)
    {
        clasters[i] = new Point[amount];
    }
    Point* meanvalue = new Point[count_clasters]; // центральные кластеры
    for (int i = 0; i < count_clasters; i++)
    {
        Point temp;
        std::cout << "Enter [" << i << "].x:";
        cin >> temp.x;
        std::cout << "Enter [" << i << "].y:";
        cin >> temp.y;
        meanvalue[i] = temp;
    }

    int* counters = new int[count_clasters]{};
    Point* old_meanvalue = new Point[count_clasters];
    double* distance = new double[count_clasters];
    do
    {
        Copy(old_meanvalue, meanvalue, count_clasters);
        
        for (int i = 0; i < amount; i++)
        {
            int temp=0;
            for (int j = 0; j < count_clasters; j++)
            {
                distance[j] = Measure_dist(points[i], meanvalue[j]);
            }
            double min = distance[0];

            for (int j = 0; j < count_clasters; j++)
            {
                if (min > distance[j])
                {
                    min = distance[j];
                    temp = j;
                }
            }
            clasters[temp, counters[temp]];
            counters[temp]++;
            Print_clusters(clasters, counters, count_clasters);
        }
    } while (flagequal(old_meanvalue, meanvalue, count_clasters));


    //do
    //{

    //    //saving old means
    //    om1 = m1;
    //    om2 = m2;

    //    //creating clusters
    //    i1 = i2 = i3 = 0;
    //    for (i1 = 0; i1 < 10; i1++)
    //    {
    //        //calculating distance to means
    //        t1 = k0[i1] - m1;
    //        if (t1 < 0)
    //        {
    //            t1 = -t1;
    //        }

    //        t2 = k0[i1] - m2;
    //        if (t2 < 0)
    //        {
    //            t2 = -t2;
    //        }

    //        if (t1 < t2)
    //        {
    //            //near to first mean
    //            k1[i2] = k0[i1];
    //            i2++;
    //        }
    //        else
    //        {
    //            //near to second mean
    //            k2[i3] = k0[i1];
    //            i3++;
    //        }

    //    }

    //    t2 = 0;
    //    //calculating new mean
    //    for (t1 = 0; t1 < i2; t1++)
    //    {
    //        t2 = t2 + k1[t1];
    //    }
    //    m1 = t2 / i2;

    //    t2 = 0;
    //    for (t1 = 0; t1 < i3; t1++)
    //    {
    //        t2 = t2 + k2[t1];
    //    }
    //    m2 = t2 / i3;

    //    //printing clusters
    //    std::cout << "\nCluster 1:";
    //    for (t1 = 0; t1 < i2; t1++)
    //    {
    //        std::cout << k1[t1] << " ";
    //    }
    //    std::cout << "\nm1=" << m1;

    //    std::cout << "\nCluster 2:";
    //    for (t1 = 0; t1 < i3; t1++)
    //    {
    //        std::cout << k2[t1] << " ";
    //    }
    //    std::cout << "\nm2=" << m2;

    //    std::cout << "\n ----";
    //} while (m1 != om1 && m2 != om2);



    //std::cout << "Enter the num of clusters\n";
    //int cl_amount;
    //cin >> cl_amount;
    //double** startdata = new double*[amount];
    //double** firstcl = new double*[amount];
    //double** secondcl = new double*[amount];
    //for (int i = 0; i < amount; i++)
    //{
    //    startdata[i] = new double[2];
    //    firstcl[i] = new double[2];
    //    secondcl[i] = new double[2];
    //}
    //std::cout << "\nEnter " << amount << " numbers:\n";
    //for (i1 = 0; i1 < amount; i1++)
    //{
    //    std::cout << "point[" << i1 << "].x:";
    //    cin >> startdata[i1][0];
    //    std::cout << "point[" << i1 << "].y:";
    //    cin >> startdata[i1][1];
    //    
    //}
    /*double m1, m2;
    std::cout << "\n Enter first meal:";
    cin >> m1;
    std::cout << "\n Enter second mean:";
    cin >> m2;
    double om1, om2;
    do
    {
        om1 = m1;
        om2 = m2;
        i1 = i2 = i3 = 0;
        for (i1 = 0; i1 < amount; i1++)
        {
            t1 = startdata[i1] - m1;
            if (t1 < 0) {
                t1 *= -1;
            }
            t2 = startdata[i1] - m2;
            if (t2 < 0) {
                t2 *= -1;
            }
            if (t1 < t2)
            {
                firstcl[i2] = startdata[i1];
                i2++;
            }
            else
            {
                secondcl[i3] = startdata[i1];
                i3++;
            }

        }
        t2 = 0;
        for (t1 = 0; t1 < i2; t1++)
        {
            t2 += firstcl[t1];
        }
        m1 = t2 / i2;
        t2 = 0;
        for (t1 = 0; t1 < i3; t1++)
        {
            t2 += secondcl[t1];
        }
        m2 = t2 / i3;
        std::cout << "\nCluster 1:";
        for (t1 = 0; t1 < i2; t1++)
        {
            std::cout << firstcl[t1] << " ";
        }
        std::cout << "\nm1=" << m1;

        std::cout << "\nCluster 2:";
        for (t1 = 0; t1 < i3; t1++)
        {
            std::cout << secondcl[t1] << " ";
        }
        std::cout << "\nm2=" << m2;

        std::cout << "\n ----";

    } while (m1 != om1 && m2 != om2);*/

    for (int i = 0; i < count_clasters; i++)
    {
        delete[]clasters[i];

    }
}
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
double Measure_distance_new(double firstX, double firstY, double secondX, double secondY )
{
    return sqrt(abs(firstX - secondX) * abs(firstX - secondX)
        + abs(firstY - secondY) * abs(firstY - secondY));
}
void Print_clusters_vectors(vector<vector<Point>> clusters, int count_clusters)
{
    for (int i = 0; i < count_clusters; i++)
    {
        cout <<"\n Cluster " << i << ": ";
        for (int j = 0; j < clusters[i].size(); j++)
        {
            std::cout << ":" << "(" << clusters[i][j].x << "," << clusters[i][j].y << ")" << "| ";
        }
        cout << endl;
    }
}
bool flagequal_vector(vector<Point> oldmean, vector<Point> mean)
{
    for (int i = 0; i < oldmean.size(); i++)
    {
        if (oldmean[i].x - mean[i].x <= 0.0001 && oldmean[i].y - mean[i].y <= 0.0001)
            return false;
    }
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

    

    /*
            clasters[temp, counters[temp]];
            counters[temp]++;
            Print_clusters(clasters, counters, count_clasters);
        }
    } while (flagequal(old_meanvalue, meanvalue, count_clasters));
    */

    //do
    //{

    //    //saving old means
    //    om1 = m1;
    //    om2 = m2;

    //    //creating clusters
    //    i1 = i2 = i3 = 0;
    //    for (i1 = 0; i1 < 10; i1++)
    //    {
    //        //calculating distance to means
    //        t1 = k0[i1] - m1;
    //        if (t1 < 0)
    //        {
    //            t1 = -t1;
    //        }

    //        t2 = k0[i1] - m2;
    //        if (t2 < 0)
    //        {
    //            t2 = -t2;
    //        }

    //        if (t1 < t2)
    //        {
    //            //near to first mean
    //            k1[i2] = k0[i1];
    //            i2++;
    //        }
    //        else
    //        {
    //            //near to second mean
    //            k2[i3] = k0[i1];
    //            i3++;
    //        }

    //    }

    //    t2 = 0;
    //    //calculating new mean
    //    for (t1 = 0; t1 < i2; t1++)
    //    {
    //        t2 = t2 + k1[t1];
    //    }
    //    m1 = t2 / i2;

    //    t2 = 0;
    //    for (t1 = 0; t1 < i3; t1++)
    //    {
    //        t2 = t2 + k2[t1];
    //    }
    //    m2 = t2 / i3;

    //    //printing clusters
    //    std::cout << "\nCluster 1:";
    //    for (t1 = 0; t1 < i2; t1++)
    //    {
    //        std::cout << k1[t1] << " ";
    //    }
    //    std::cout << "\nm1=" << m1;

    //    std::cout << "\nCluster 2:";
    //    for (t1 = 0; t1 < i3; t1++)
    //    {
    //        std::cout << k2[t1] << " ";
    //    }
    //    std::cout << "\nm2=" << m2;

    //    std::cout << "\n ----";
    //} while (m1 != om1 && m2 != om2);



    //std::cout << "Enter the num of clusters\n";
    //int cl_amount;
    //cin >> cl_amount;
    //double** startdata = new double*[amount];
    //double** firstcl = new double*[amount];
    //double** secondcl = new double*[amount];
    //for (int i = 0; i < amount; i++)
    //{
    //    startdata[i] = new double[2];
    //    firstcl[i] = new double[2];
    //    secondcl[i] = new double[2];
    //}
    //std::cout << "\nEnter " << amount << " numbers:\n";
    //for (i1 = 0; i1 < amount; i1++)
    //{
    //    std::cout << "point[" << i1 << "].x:";
    //    cin >> startdata[i1][0];
    //    std::cout << "point[" << i1 << "].y:";
    //    cin >> startdata[i1][1];
    //    
    //}
    /*double m1, m2;
    std::cout << "\n Enter first meal:";
    cin >> m1;
    std::cout << "\n Enter second mean:";
    cin >> m2;
    double om1, om2;
    do
    {
        om1 = m1;
        om2 = m2;
        i1 = i2 = i3 = 0;
        for (i1 = 0; i1 < amount; i1++)
        {
            t1 = startdata[i1] - m1;
            if (t1 < 0) {
                t1 *= -1;
            }
            t2 = startdata[i1] - m2;
            if (t2 < 0) {
                t2 *= -1;
            }
            if (t1 < t2)
            {
                firstcl[i2] = startdata[i1];
                i2++;
            }
            else
            {
                secondcl[i3] = startdata[i1];
                i3++;
            }

        }
        t2 = 0;
        for (t1 = 0; t1 < i2; t1++)
        {
            t2 += firstcl[t1];
        }
        m1 = t2 / i2;
        t2 = 0;
        for (t1 = 0; t1 < i3; t1++)
        {
            t2 += secondcl[t1];
        }
        m2 = t2 / i3;
        std::cout << "\nCluster 1:";
        for (t1 = 0; t1 < i2; t1++)
        {
            std::cout << firstcl[t1] << " ";
        }
        std::cout << "\nm1=" << m1;

        std::cout << "\nCluster 2:";
        for (t1 = 0; t1 < i3; t1++)
        {
            std::cout << secondcl[t1] << " ";
        }
        std::cout << "\nm2=" << m2;

        std::cout << "\n ----";

    } while (m1 != om1 && m2 != om2);*/

    /*for (int i = 0; i < count_clasters; i++)
    {
        delete[]clasters[i];

    }*/
}
void main()
{
    //k_means();
    k_means_2x_with_vector();

    //onemeasure();

    //ending
    //getch();
}

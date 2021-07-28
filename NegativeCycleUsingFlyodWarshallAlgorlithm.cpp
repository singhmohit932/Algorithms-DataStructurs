for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        for (int t = 0; t < n; ++t) {
            if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
                d[i][j] = - INF; 
        }
    }
}
/***********
Run Floyd-Warshall algorithm on the graph. Initially d[v][v]=0 for each v. But after running the 
algorithm d[v][v] will be smaller than 0 if there exists a negative length path from v to v. 
We can use this to also find all pairs of vertices that don't have a shortest path between them. 
We iterate over all pairs of vertices (i,j) and for each pair we check whether they have a shortest path 
between them. To do this try all possibilities for an intermediate vertex t. (i,j) doesn't have a shortest path,
if one of the intermediate vertices t has d[t][t]<0 (i.e. t is part of a cycle of negative weight), t can be 
reached from i and j can be reached from t. Then the path from i to j can have arbitrarily small weight. 
We will denote this with -INF.

******/
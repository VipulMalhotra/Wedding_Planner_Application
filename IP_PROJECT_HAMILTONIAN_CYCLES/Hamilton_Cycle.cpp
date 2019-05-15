#include<stdio.h>
#include<cstdlib>
#include<time.h>
#include<cstring>
#include<string>

clock_t begin, end;
int job_done=0;

void swap(int graph[V][V],int index){
int temp[V];
int i,j;
//copy graph[0][] inside temp[] and then move temp[] to graph[index][]
for(i=0;i<V;i++){
temp[i]=graph[0][i];
}
for(i=0;i<V;i++){
graph[0][i]=graph[index][i];
}
for(i=0;i<V;i++){
graph[index][i]=temp[i];
}
//copy graph[][0] inside temp[] and then move temp[] to graph[][index]
for(i=0;i<V;i++){
temp[i]=graph[i][0];
}
for(i=0;i<V;i++){
graph[i][0]=graph[i][index];
}
for(i=0;i<V;i++){
graph[i][index]=temp[i];
}

}

void printSolution(int path[],int change);

/* A utility function to check if the vertex v can be added at
   index 'pos' in the Hamiltonian Cycle constructed so far (stored
   in 'path[]') */
int isSafe(int v, int graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
    if (graph [ path[pos-1] ][ v ] == 0)
        return 0;

    /* Check if the vertex has already been included.
      This step can be optimized by creating an array of size V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

/* A recursive utility function to solve hamiltonian cycle problem */
int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    end=clock();
    double spent=(double)(end - begin) / CLOCKS_PER_SEC;
    if(spent>2.0){return 0;}

    /* base case: If all vertices are included in Hamiltonian Cycle */
    if (pos == V)
    {
        // And if there is an edge from the last included vertex to the
        // first vertex
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return 1;
        else
          return 0;
    }

    // Try different vertices as a next candidate in Hamiltonian Cycle.
    // We don't try for 0 as we included 0 as starting point in in hamCycle()
    for (int v = 1; v < V; v++)
    {
        /* Check if this vertex can be added to Hamiltonian Cycle */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            /* recur to construct rest of the path */
            if (hamCycleUtil (graph, path, pos+1) == 1)
                return 1;

            /* If adding vertex v doesn't lead to a solution,
               then remove it */
            path[pos] = -1;
        }
    }

    /* If no vertex can be added to Hamiltonian Cycle constructed so far,
       then return 0 */
    return 0;
}

/* This function solves the Hamiltonian Cycle problem using Backtracking.
  It mainly uses hamCycleUtil() to solve the problem. It returns 0
  if there is no Hamiltonian Cycle possible, otherwise return 1 and
  prints the path. Please note that there may be more than one solutions,
  this function prints one of the feasible solutions. */
int hamCycle(int graph[V][V],int change)
{
    begin = clock();
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    /* Let us put vertex 0 as the first vertex in the path. If there is
       a Hamiltonian Cycle, then the path can be started from any point
       of the cycle as the graph is undirected */
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == 0 )
    {
        printf("...\n");
        return 0;
    }

    printSolution(path,change);
    return 1;
}

/* A utility function to print solution */
void printSolution(int path[],int change)
{
    job_done=1;
    printf("Following is a possible seating arrangement for the guests-\n");
    printf(" %d ",change);
    for (int i = 1; i < V; i++)
      { if(path[i]==change){printf(" %d ",0);}
else
 printf(" %d ", path[i]);

}

    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", change);
    printf("\n");
}

// driver program to test above function
int main()
{
int graph[V][V];
int i,j;
if(USER_OPINION==2){
system("clear");
printf("Enter 1 to give input through GUI, 2 for giving adjacency-matrix input-\n");
int way;
scanf("%d",&way);
if(way==1){
system("bash main2.sh");
for(i=0;i<V;i++){
for(j=0;j<V;j++){
graph[i][j]=0;
}
}
//getting input from temp.tmp
FILE *ptr=fopen("temp.tmp","r");
int index=0;
while(!feof(ptr)){
int temporary;
fscanf(ptr,"%d",&temporary);
if(temporary!=-1996){
graph[index][temporary]=1;
graph[temporary][index]=1;
}
if(temporary==-1996){index++;}
}
fclose(ptr);
}
else {
for(i=0;i<V;i++){
    for(j=0;j<V;j++){
        int temp;
        scanf("%d",&temp);
        graph[i][j]=(int)temp;
        }
 }

}

int upto;
if(MAX_ITER==0){upto=V;}
else if(MAX_ITER==1){upto=1;}
system("clear");
for(i=0;i<upto;i++){
swap(graph,i);
hamCycle(graph,i);
swap(graph,i);
}

}
else {

FILE *ptr=fopen("Hamilton_Cycle_500_Input.txt","r");
 for(i=0;i<V;i++){
    for(j=0;j<V;j++){
        int temp;
        fscanf(ptr,"%d",&temp);
        graph[i][j]=(int)temp;
        }
 }
fclose(ptr);
int upto;
if(MAX_ITER==0){upto=V;}
else if(MAX_ITER==1){upto=1;}
system("clear");
for(i=0;i<upto;i++){
swap(graph,i);
hamCycle(graph,i);
swap(graph,i);
}

}
if(job_done==0){
printf("The program cannot find any suitable seating arrangement.\n");
}

 return 0;
}

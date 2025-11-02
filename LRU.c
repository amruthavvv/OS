#include<stdio.h>
#include<limits.h>
int main(){
  int n, frames;
  scanf("%d", &n);
  int pages[n];
  for(int i=0;i<n;i++) scanf("%d", &pages[i]);
  scanf("%d", &frames);
  int fr[frames], r[frames];
  for(int i=0;i<frames;i++){ fr[i]=-1; r[i]=0; }
  int pgft=0, time=0;
  for(int i=0;i<n;i++){
    int p=pages[i], found=0;
    for(int j=0;j<frames;j++){
      if(fr[j]==p){ r[j]=time++; found=1; break; }
    }
    if(!found){
      int replaceindex=-1, mintime=INT_MAX;
      for(int j=0;j<frames;j++){
        if(fr[j]==-1){ replaceindex=j; break; }
        if(r[j]<mintime){ mintime=r[j]; replaceindex=j; }
      }
      fr[replaceindex]=p;
      r[replaceindex]=time++;
      pgft++;
    }
    printf("Page %d -> ", p);
    for(int j=0;j<frames;j++){
      if(fr[j]==-1) printf("- ");
      else printf("%d ", fr[j]);
    }
    if(!found) printf("Page Fault");
    printf("\n");
  }
  printf("\nTotal Page Faults: %d\n", pgft);
  return 0;
}

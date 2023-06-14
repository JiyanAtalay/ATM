#include <stdio.h>
#include <stdlib.h>

struct kişi{
    char ad[20];
    char soyad[30];
    int yaş;
    char numara[12];
};

void menü(void){
    printf("   Rehbere hoşgeldiniz\n");
    printf("-------------------------\n");
    printf("[1]-Rehberdeki kişileri yazdır\n[2]-Yeni kişi ekle\n[9]-Rehberden çık\nSeçiminiz:");
}

void kişiekle(struct kişi *rehber){
    int s;
    for(s=0;s<50;s++){
        if(rehber[s].yaş==-1)
            break;
    }
    printf("Adınız:");
    scanf("%s",rehber[s].ad);
    printf("Soyadınız:");
    scanf("%s",rehber[s].soyad);
    printf("Yaşınız:");
    scanf("%d",&rehber[s].yaş);
    printf("Numaranız:");
    scanf("%s",rehber[s].numara);
    
    printf("\nNumara başarıyla kaydedildi");
    rehber[s+1].yaş=-1;
}

void rehberiyazdır(struct kişi *rehber){
    int s,i=1;
    for(s=0;s<50;s++){
        if(rehber[s].yaş==-1){
            break;
        }
        printf("%d-%s %s  %d   %s\n",i,rehber[s].ad,rehber[s].soyad,rehber[s].yaş,rehber[s].numara);
        i++;
    }
}
void kaydet(struct kişi *rehber){
    FILE *dosya=fopen("/Users/jiyanatalay/Desktop/belgeler/yeni.txt","w");
    
    int s;
    for(s=0;s<50;s++){
        if(rehber[s].yaş==-1){
            break;
        }
        fprintf(dosya,"%s %s  %d   %s\n",rehber[s].ad,rehber[s].soyad,rehber[s].yaş,rehber[s].numara);
    }
    fclose(dosya);
}

void rehhberoku(struct kişi *rehber){
    FILE *dosya=fopen("/Users/jiyanatalay/Desktop/belgeler/yeni.txt","r");
    if(dosya== NULL)
        return;
    int s;
    for(s=0;s<50;s++){
        fscanf(dosya,"%s %s %d %s\n",rehber[s].ad,rehber[s].soyad,&(rehber[s].yaş),rehber[s].numara);
        if(feof(dosya)==1)
            break;
    }
    rehber[s+1].yaş=-1;
    fclose(dosya);
}

int main(void){
    
    int flag=0,seçim;
    
    struct kişi rehber[50];
    
    rehber[0].yaş=-1;
    rehhberoku(rehber);
    
    while(flag==0){
        
        menü();
        scanf("%d",&seçim);
        
        switch(seçim){
            case 1:{
                rehberiyazdır(rehber);
                break;
            }
            case 2:{
                kişiekle(rehber);
                break;
            }
            case 9:{
                kaydet(rehber);
                flag=1;
                break;
            }
            default:{
                printf("Yanlış rakam girdiniz!");
                break;
            }
        }
        printf("\n\n\n\n");
    }
    
    
    return 0;
}

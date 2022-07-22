#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
int spaceFind(char text[])  // Number of spaces gives the number of words 
{
    int spaceCounter=0;
    for(int i=0; text[i] != '\0';i++)
    {
        if(text[i]== ' '){
            spaceCounter++;
        }
    }
  return spaceCounter;
}
int numberOfLetters(char text[])
{
    int letterCounter=0;
    int spaceConter=spaceFind(text);
    for(int i=0;text[i] !='\0';i++)
    {
      if(text[i] != '.' && text[i] != ',' && text[i] != '?' && text[i] != '!' && text[i] != '...' && text[i] != ';')// Preventing punctuation marks from being counted as letters
      {
          letterCounter++;
      }
    }
   return letterCounter-spaceConter;
}
int numberOfSentences(char text[])
{
    int sentencesCounter=0;
    for(int i=0; text[i] != '\0';i++)
    {
        if(text[i]=='.' || text[i]=='?' || text[i]=='!' || text[i]==':' )
        {
            sentencesCounter++;
        }
        if(text[i] == '.' && text[i+1] =='.' && text[i+2] == '.')//Makes three dots count as one punctuation mark
        {
            sentencesCounter= sentencesCounter-2;
        }
    }
  return sentencesCounter;
}
int numberOfWords(char text[])
{
    int spaceCounter=spaceFind(text);
    int punctuation=0;
    int appendices=0;
    for(int i =0;text[i]!='\0';i++)//so that suffixes do not count as words
    {
        if(text[i]== ' ' && text[i+1]== 'd' && text[i+2]=='e' && text[i+3]==' ')
        {
            spaceCounter=spaceCounter-1;
        }
        if(text[i]== ' ' && text[i+1]== 'd' && text[i+2]=='a' && text[i+3]==' ')
        {
            spaceCounter=spaceCounter-1;
        }
        if(text[i]== ' ' && text[i+1]== 'k' && text[i+2]=='i' && text[i+3]==' ')
        {
            spaceCounter=spaceCounter-1;
        }
    }
  return spaceCounter;
}
void findTheWord(char text[],char word[])
{
    if(strstr(text,word) != NULL){
        printf("We found the %s",word);
    }
    else{
        printf("We couldnt't find the %s",word);
    }
}
void findThePluralWord(char text[])
{
    char *wordPtr;
    wordPtr=strtok(text," ");//Shreds the text and searches for the word in each piece
    int counter=0;
    printf("\nPlural Words= ");
    while(wordPtr !=NULL)//Returns the pointer to null
    {
        for(int i=0;wordPtr[i] != '\0';i++)
        {
            if(wordPtr[i]=='l' && wordPtr[i+1]=='e' && wordPtr[i+2]=='r')
            {
               counter++;
               printf("%s ",wordPtr);
            }
            if(wordPtr[i]=='l' && wordPtr[i+1]=='a' && wordPtr[i+2]=='r')
            {
               counter++;
               printf("%s ",wordPtr);
            }
        }
      wordPtr=strtok(NULL," ");//continuation of shredding
    }
    printf("\nA total %d plural words were found in the text\n",counter);
}
int findConsonants(char text[])
{
    int countCons=0;
    for(int i=0;text[i]!='\0';i++)
    {
        if(text[i]=='p' || text[i]=='P' || text[i]=='t' || text[i]=='T' || text[i]=='k' || text[i]=='K')//Finding hard consonants(except for Turkish consonants)
        {
            countCons++;
        }
    }
    return countCons;
}
int findSoftConsonants(char text[])
{
    int softCount=0;
    for(int i=0;text[i]!='\0';i++)
    {
        if( text[i]=='B' || text[i]=='b' || text[i]=='C' || text[i]=='c' || text[i]=='D' || text[i]=='d' || text[i]=='G' || text[i]=='g' ||
           text[i]=='J' || text[i]=='j' || text[i]=='L' || text[i]=='l' || text[i]=='M' || text[i]=='m' || text[i]=='N' || text[i]=='n' ||
           text[i]=='R' || text[i]=='r' || text[i]=='V' || text[i]=='v' || text[i]=='Y' || text[i]=='y' || text[i]=='Z' || text[i]=='z' )//Finds soft consonants
        {
            softCount++;
        }
    }
    return softCount;
}
void findConnexion(char text[])
{
    char *connexionPtr;
    connexionPtr=strtok(text," ");
    char word1[50];//We are assingning 2 variables so that we will operate in 2 words
    char word2[50];
    strcpy(word1,connexionPtr);//Copy the text to word1

    while(connexionPtr != NULL)//We continue until the word text in empty
    {
        connexionPtr=strtok(NULL," ");
        strcpy(word2,connexionPtr);//We throw out the 2nd word
        for(int i=0; word1 !='\0'; i++)
        {
            //We are looking for the rule in the first word(except for Turkish consonants)
            if(word1[i]=='b' ||word1[i]=='c' ||word1[i]=='d' ||word1[i]=='g'  ||word1[i]=='h' ||word1[i]=='j' ||word1[i]=='k' ||
               word1[i]=='l' ||word1[i]=='m' ||word1[i]=='n' ||word1[i]=='p' ||word1[i]=='r' ||word1[i]=='s' ||word1[i]=='t' ||
               word1[i]=='v' ||word1[i]=='y' ||word1[i]=='z' )

            { //If we find the rule we look at word2(except for Turkish consonants)
                if(word2[0]=='A' ||word2[0]=='a' ||word2[0]=='E' ||word2[0]=='e' ||word2[0]=='I' ||word2[0]=='i' ||word2[0]=='O' ||word2[0]=='o'  ||word2[0]=='U' ||word2[0]=='u'  ){
                    printf(" %s %s,",word1,word2);
                    break;
                }
            }


        }
        strcpy(word1,word2);//we empty word2 and discard word1
    }
}
void findBigHarmony(char text[])
{
    // Turkish characters are not included in this function
    int count=0,count1=0;
    char *harmonyPtr;
    harmonyPtr=strtok(text," ");
    printf("\nWords that fit great vowel harmony= ");
    while(harmonyPtr != NULL)
    {
        for(int i=0;harmonyPtr[i]!='\0';i++)
        {
            if(harmonyPtr[i]=='a' ||harmonyPtr[i]=='A' ||harmonyPtr[i]=='I' ||harmonyPtr[i]=='o' ||harmonyPtr[i]=='O' ||harmonyPtr[i]=='u' ||harmonyPtr[i]=='U' )
            {
                count++;
            }
            if(harmonyPtr[i]=='E' ||harmonyPtr[i]=='e'  ||harmonyPtr[i]=='i' )
            {
                count1++;
            }
        }
        if(count>1 && count1==0)
        {
            printf("%s ",harmonyPtr);
        }
        if(count==0 && count1>1)
        {
            printf("%s ",harmonyPtr);
        }
        count1=0;
        count=0;
        harmonyPtr=strtok(NULL," ");
    }
}
void findSmallHarmony(char text[])
{
    // Turkish characters are not included in this function
    char *harmonyPtr;
    int counter1,counter2,counter3,k;
    counter1=0;
    counter2=0;
    counter3=0;
    harmonyPtr=strtok(text," ");
    printf("\nWords that match minor vowel harmony=");
    while(harmonyPtr != NULL)
    {
        for(int i=0;i<strlen(harmonyPtr);i++)
        {
            if(harmonyPtr[i]=='a' ||harmonyPtr[i]=='A' ||harmonyPtr[i]=='E' ||harmonyPtr[i]=='e' ||
               harmonyPtr[i]=='I' ||harmonyPtr[i]=='i' )
            {
                k=i+1;
                for(k;k<strlen(harmonyPtr);k++){
                    if(harmonyPtr[k]=='a' || harmonyPtr[k]=='e'  || harmonyPtr[k]=='i'){
                        counter1++;
                    }
                    else if(harmonyPtr[k]=='o'  ||harmonyPtr[k]=='u' ){
                        counter3++;
                        break;
                    }

                }
            }
            if(harmonyPtr[i]=='O' ||harmonyPtr[i]=='o'  ||
               harmonyPtr[i]=='U' ||harmonyPtr[i]=='u' ){
                k=i+1;
                for(k;k<strlen(harmonyPtr);k++){
                    if(harmonyPtr[k]=='a' ||harmonyPtr[k]=='e' ||harmonyPtr[k]=='u'  ){
                        counter2++;
                    }
                    else if(harmonyPtr[k]=='o'||harmonyPtr[k]=='i'){
                        counter3++;
                        break;
                    }

                }
               }
        }

        if(counter1>0 && counter3==0){
            printf("%s ",harmonyPtr);
        }
        if(counter2>0 && counter3==0){
            printf("%s ",harmonyPtr);
        }

        harmonyPtr=strtok(NULL," ");
    }
}
int smallMenu(void)//Where the last query was made
{
    char selection;
    int flag =1;
    int a=1;
    int b=0;
    do
    {
        printf("\nWould you like to look at another feature?[Y-y/N-n]\n");
        scanf(" %c",&selection);
        if(selection=='Y' || selection=='y')
        {
            flag=0;
            return a;
        }
        if(selection=='N' || selection=='n')
        {
            flag=0;
            return b;
        }
        else
        {
            printf("\nYou entered incorrectly, please enter again.\n");
            flag=1;
        }
    }while(flag==1);

}

int main()
{
    //  It can be added in Turkish characters by making the following plugins
    //setlocale(LC_ALL,"Turkish_turkish.1254");
    //SetConsoleCP(1254);
    //SetConsoleOutputCP(1254);

    int flag=1;
    char selection[25];
    char answer;
    char text[100000];
    printf("Enter the test you want to look at the feartures of \n");
    gets(text);





    char array1[]="Connexion";
    char array2[]="Great Vowel Harmony";
    char array3[]="Little Celebrity Match";
    char array4[]="Plural Words";
    char array5[]="Word Count";
    char array6[]="Number of Sentences";
    char array7[]="Number of Letters";
    char array8[]="Word Search";
    char array9[]="Soft Consonants";
    char array10[]="Hard Consonants";
    char array11[]="Exit";

        do{
         printf("\nHere, show the user how the rules should be written:\n");
         printf("1-)Connexion\n");
         printf("2-)Great Vowel Harmony\n");
         printf("3-)Little Celebrity Match\n");
         printf("4-)Plural Words\n");
         printf("5-)Word Count\n");
         printf("6-)Number of Sentences\n");
         printf("7-)Number of Letters\n");
         printf("8-)Word Search\n");
         printf("9-)Soft Consonants\n");
         printf("10-)Hard Consonants\n");
         printf("11-)Exit\n");
         gets(selection);








         if(strcmp(selection,array1)==0)
         {
            char copyText[100000];
            strcpy(copyText,text);
            findConnexion(copyText);
            flag=smallMenu();
         }
         if(strcmp(selection,array2)==0)
         {
            char copyText[100000];
            strcpy(copyText,text);
            findBigHarmony(copyText);
            flag=smallMenu();
         }
         if(strcmp(selection,array3)==0)
         {
            char copyText[100000];
            strcpy(copyText,text);
            findSmallHarmony(copyText);
            flag=smallMenu();
         }
         if(strcmp(selection,array4)==0)
         {
            char copyText[100000];
            strcpy(copyText,text);
            findThePluralWord(copyText);
            flag=smallMenu();
         }
         if(strcmp(selection,array5)==0)
         {
           printf("%d words found.",numberOfWords(text));
           flag=smallMenu();
         }
         if(strcmp(selection,array6)==0)
         {
           printf("%d sentences found\n",numberOfSentences(text));
           flag=smallMenu();
         }
         if(strcmp(selection,array7)==0)
         {
             printf("%d letters found\n",numberOfLetters(text));
             flag=smallMenu();
         }
         if(strcmp(selection,array8)==0)
         {
           char word[100];
           printf("\nEnter the word you want to search:\n");
           scanf("%s",word);
           findTheWord(text,word);
           flag=smallMenu();

         }
         if(strcmp(selection,array9)==0)
         {
               printf("\n%d soft consonants found.\n",findSoftConsonants(text));
               flag=smallMenu();
         }
         if(strcmp(selection,array10)==0)
         {
             printf("\n%d strong consonants found.\n",findConsonants(text));
             flag=smallMenu();
         }
         if(strcmp(selection,array11)==0)
         {
             int temp=1;
                 do{
                 printf("Are you sure you want to exit?[Y-y/N-n]\n");
                 scanf(" %c",&answer);
                 if(answer == 'N' || answer =='n'){
                    flag=1;
                    temp=0;
                 }
                 if(answer=='Y' || answer=='y'){
                    flag=0;
                    temp=0;
                 }
                 else if(answer != 'N' || answer !='n' || answer == 'Y' || answer =='y'){
                    printf("\nYou entered incorrectly, please enter again.\n");
                    temp=1;
                 }
                 }while(temp==1);

         }
         if(strcmp(selection,array1)!=0 && strcmp(selection,array2)!=0 && strcmp(selection,array3)!=0 && strcmp(selection,array4)!=0 &&
            strcmp(selection,array5)!=0 && strcmp(selection,array6)!=0 && strcmp(selection,array7)!=0 && strcmp(selection,array8)!=0 &&
            strcmp(selection,array9)!=0 && strcmp(selection,array10)!=0 && strcmp(selection,array11)!=0){
             printf("\nYou entered incorrectly, please enter again.");
             printf("\nType as shown!");
             }

     }while(flag==1);























    return 0;
}

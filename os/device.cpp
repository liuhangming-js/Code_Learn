#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
//æ°æ®ç»æ
typedef struct node
{
    char name[10];
    char devname[10];
    struct node *next;
} PCB;    //è¿ç¨
PCB *run; //æ§è¡éå
//
typedef struct Node
{
    char identify[10]; //æ è¯
    int state;         //è®¾å¤ç¶æ
    PCB *blocking;     //é»å¡éåæé
} CHCT;                //ééæ§å¶è¡¨
CHCT *CH1, *CH2;       //è®¾ç½®ä¸¤ä¸ªééä¸ºch1,ch2
//
typedef struct NOde
{
    char identify[10]; //æ è¯
    int state;         //è®¾å¤ç¶æ
    CHCT *chct;        // CHCT
    PCB *blocking;     //é»å¡éåæé
    struct NOde *next;
} COCT; //æ§å¶å¨æ§å¶è¡¨
COCT *cohead;
typedef struct NODe
{
    char identify[10]; //æ è¯
    char type;         //è®¾å¤ç±»å
    int state;         //è®¾å¤ç¶æ
    int times;         //éå¤æ§è¡æ¬¡æ°
    PCB *blocking;     //é»å¡éåæé
    COCT *coct;        // COCT
} DCT;                 //è®¾å¤æ§å¶è¡¨
typedef struct NODE
{
    char type;         //ç±»å«
    char identify[10]; //æ è¯
    DCT *dct;          // DCTè®¾å¤æ§å¶è¡¨
    //é©±å¨å¥å£å°å
    struct NODE *next;
} SDT;
//ç³»ç»è®¾å¤è¡¨
SDT *head;
SDT *checkdel;
void Init()
{
    PCB *ch1block, *ch2block, *co1block, *co2block, *co3block, *d1block, *d2block, *d3block, *d4block; //è¿ç¨æ§å¶å
    COCT *CO1, *CO2, *CO3;
    DCT *d1, *d2, *d3, *d4;
    SDT *s1, *s2, *s3, *s4;
    //=================================================
    run = (PCB *)malloc(sizeof(PCB));
    run->next = NULL;
    CH1 = (CHCT *)malloc(sizeof(CHCT));
    CH2 = (CHCT *)malloc(sizeof(CHCT));
    strcpy(CH1->identify, "ch1");
    strcpy(CH2->identify, "ch2");
    CH1->state = 0;
    CH2->state = 0;
    ch1block = (PCB *)malloc(sizeof(PCB));
    ch1block->next = NULL;
    ch2block = (PCB *)malloc(sizeof(PCB));
    ch2block->next = NULL;
    CH1->blocking = ch1block;
    CH2->blocking = ch2block;
    cohead = (COCT *)malloc(sizeof(COCT));
    cohead->next = NULL;
    CO1 = (COCT *)malloc(sizeof(COCT));
    cohead->next = CO1;
    CO1->next = NULL;
    CO2 = (COCT *)malloc(sizeof(COCT));
    CO1->next = CO2;
    CO2->next = NULL;
    CO3 = (COCT *)malloc(sizeof(COCT));
    CO2->next = CO3;
    CO3->next = NULL;
    CO1->state = 0;
    CO2->state = 0;
    CO3->state = 0;
    co1block = (PCB *)malloc(sizeof(PCB));
    co1block->next = NULL;
    co2block = (PCB *)malloc(sizeof(PCB));
    co2block->next = NULL;
    co3block = (PCB *)malloc(sizeof(PCB));
    co3block->next = NULL;
    strcpy(CO1->identify, "co1");
    strcpy(CO2->identify, "co2");
    strcpy(CO3->identify, "co3");
    CO1->chct = CH1;
    CO2->chct = CH1;
    CO3->chct = CH2;
    CO1->blocking = co1block;
    CO2->blocking = co2block;
    CO3->blocking = co3block;
    //=====================================================
    d1block = (PCB *)malloc(sizeof(PCB));
    d2block = (PCB *)malloc(sizeof(PCB));
    d3block = (PCB *)malloc(sizeof(PCB));
    d4block = (PCB *)malloc(sizeof(PCB));
    d1block->next = NULL;
    d2block->next = NULL;
    d3block->next = NULL;
    d4block->next = NULL;
    d1 = (DCT *)malloc(sizeof(DCT));
    strcpy(d1->identify, "P"); // pè¡¨ç¤ºæå°æºè®¾å¤
    d2 = (DCT *)malloc(sizeof(DCT));
    strcpy(d2->identify, "T"); // tè¡¨ç¤ºæ¾ç¤ºå¨è®¾å¤
    d3 = (DCT *)malloc(sizeof(DCT));
    strcpy(d3->identify, "K"); // kè¡¨ç¤ºé®çè®¾å¤
    d4 = (DCT *)malloc(sizeof(DCT));
    strcpy(d4->identify, "M"); // mè¡¨ç¤ºé¼ æ è®¾å¤
    d1->coct = CO1;            //æ§å¶å¨
    d2->coct = CO2;
    d3->coct = CO3;
    d4->coct = CO3;
    d1->state = 0; //ç¶æ
    d2->state = 0;
    d3->state = 0;
    d4->state = 0;
    d1->type = 'o'; // oè¡¨ç¤ºè¾åºè®¾å¤output
    d2->type = 'o';
    d3->type = 'i'; // iè¡¨ç¤ºè¾å¥è®¾å¤
    d4->type = 'i';
    d1->blocking = d1block;
    d2->blocking = d2block;
    d3->blocking = d3block;
    d4->blocking = d4block;
    //================================
    head = (SDT *)malloc(sizeof(SDT));
    head->next = NULL;
    s1 = (SDT *)malloc(sizeof(SDT));
    s2 = (SDT *)malloc(sizeof(SDT));
    s3 = (SDT *)malloc(sizeof(SDT));
    s4 = (SDT *)malloc(sizeof(SDT));
    head->next = s1;
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = NULL;
    s1->dct = d1;
    s2->dct = d2;
    s3->dct = d3;
    s4->dct = d4;
    strcpy(s1->identify, "P");
    strcpy(s2->identify, "T");
    strcpy(s3->identify, "K");
    strcpy(s4->identify, "M");
    s1->type = 'o';
    s2->type = 'o';
    s3->type = 'i';
    s4->type = 'i';
    // test
    SDT *temp = head->next;
}
//============================================
//æ·»å è®¾å¤æ¶åï¼æ·»å æ°æ§å¶å¨ï¼ææ§å¶å¨å å°æå
void Addcotrol(COCT *temp) //æ·»å æ§å¶å¨å½æ°
{
    COCT *cotemp = cohead;
    while (cotemp->next != NULL)
    {
        cotemp = cotemp->next;
    }
    cotemp->next = temp;
    temp->next = NULL;
}
//æ¥çæææ§å¶å¨ï¼éæ©æè¦è¿æ¥çæ§å¶å¨
void Showallco()
{
    COCT *temp = cohead->next;
    while (temp != NULL)
    {
        cout << temp->identify << "  ";
        temp = temp->next;
    }
    cout << endl;
}
//æ¥æ¾è¦è¿æ¥çæ§å¶å¨
COCT *Findco(char a[])
{
    COCT *temp = cohead->next;
    while (temp != NULL)
    {
        if (!strcmp(temp->identify, a))
        {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}
//å é¤è®¾å¤æ¶åï¼å¤æ­æ¯ä¸æ¯åæ¶å é¤æ§å¶å¨,ç­äº1å ï¼0ä¸å 
int sf_deleteco(char a[], char b[])
{
    SDT *temp;
    temp = head->next;
    while (temp != NULL)
    {
        if ((strcmp(temp->identify, a)) && ((!strcmp(temp->dct->coct->identify, b))))
        {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}
//å é¤è®¾å¤çæ¶ååæ¶å é¤æ§å¶å¨
void Deletecotrol(COCT *te)
{
    COCT *temp = cohead;
    while (temp->next != te)
    {
        temp = temp->next;
    }
    temp->next = te->next;
    delete (te);
}
//æ·»å è®¾å¤ï¼æ¥æ¾è®¾å¤æ¯ä¸æ¯å·²ç»å­å¨
int sf_exist(char a[])
{
    SDT *temp;
    if (head->next == NULL)
    {
        return 0;
    }
    else
    {
        temp = head->next;
        while (temp != NULL)
        {
            if (!strcmp(a, temp->identify))
            {
                checkdel = temp;
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
}
//ç³è¯·è®¾å¤æ¶åï¼å¦æå¿ï¼å°è®¾å¤æå°ç­å¾éå
void Addwaitpcb(PCB *p1, PCB *p2)
{
    PCB *temp = p1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p2;
    p2->next = NULL;
}
//åæ¶è®¾å¤æ¶åï¼å¯¹PCBçæä½
void Deletepcb(char a[])
{
    PCB *temp2 = run->next, *temp = run;
    while (temp2 != NULL)
    {
        if (!strcmp(temp2->devname, a))
        {
            temp->next = temp2->next;
            delete (temp2);
            break;
        }
        temp = temp2;
        temp2 = temp->next;
    }
}
//å¤æ­ç­å¾éåæ¯ä¸æ¯ç©º
int sf_pcbnull(PCB *temp)
{
    if (temp->next == NULL)
    {
        return 0;
    }
    else
        return 1;
}
//æ¥çææè®¾å¤ç¶æ
void Showmenu()
{
    PCB *ptemp = run->next;
    SDT *temp = head->next;
    DCT *dtemp;
    COCT *cotemp;
    CHCT *chtemp;
    cout << "SDT"
         << "    i/o"
         << "      COCT"
         << "            CHCT" << endl;
    while (temp != NULL)
    {
        dtemp = temp->dct;
        cotemp = dtemp->coct;
        chtemp = cotemp->chct;
        cout << dtemp->identify << "[" << dtemp->state << "]"
             << "\t" << dtemp->type << "\t" << cotemp->identify << "[" << cotemp->state << "]"
             << "     \t" << chtemp->identify << "[" << chtemp->state << "]" << endl;
        temp = temp->next;
    }
    while (ptemp != NULL)
    {
        cout << "è¿ç¨" << ptemp->name << "ç³è¯·äºè®¾å¤" << ptemp->devname << endl;
        ptemp = ptemp->next;
    }
    cout << endl;
}
//è®¾å¤ç¬ç«æ§æ¶åæ¥æ¾è¦æ¥æ¾çç±»åæ¯ä¸æ¯å­å¨
int sf_typeexist(char ch)
{
    SDT *temp;
    if (head->next == NULL)
    {
        return 0;
    }
    else
    {
        temp = head->next;
        while (temp != NULL)
        {
            if (temp->type == ch)
            {
                return 1;
            }
            else
                temp = temp->next;
        }
    }
    return 0;
}
//å¢å è®¾å¤
void Adddevice()
{
    cout << "å¢å è®¾å¤" << endl; //åå¥è®¾å¤åç§°
    SDT *stemp, *s2temp;
    COCT *cotemp;
    DCT *temp;
    char temptype;
    PCB *tempblock, *cotempblock;
    char choice;
    char eqary[10], coary[10];
    cin >> eqary;
    //æ­¤å¤æ¥æ¾SDTï¼çæ¯å¦æè¦æ·»å çè®¾å¤å·²ç»å­å¨
    if (sf_exist(eqary) == 1)
    { //è®¾å¤å·²ç»å­å¨
        cout << "è®¾å¤å·²å­å¨" << endl;
    }
    else
    { //è®¾å¤ä¸å­å¨
        tempblock = (PCB *)malloc(sizeof(PCB));
        tempblock->next = NULL;
        temp = (DCT *)malloc(sizeof(DCT));
        strcpy(temp->identify, eqary);
        temp->blocking = tempblock;
        temp->state = 0;
        cout << "è¾å¥è®¾å¤ç±»å" << endl;
        cin >> temptype;
        temp->type = temptype;
        stemp = (SDT *)malloc(sizeof(SDT));
        stemp->next = NULL;
        stemp->dct = temp;
        stemp->type = temptype;
        strcpy(stemp->identify, eqary);
        s2temp = head;
        while (s2temp->next != NULL)
        {
            s2temp = s2temp->next;
        }
        s2temp->next = stemp;
        stemp->next = NULL;
        cout << "æ¯å¦æ·»å æ§å¶å¨?(y/n)" << endl;
        cin >> choice;
        if ((choice == 'y') || (choice == 'Y'))
        { //æ·»å æ°æ§å¶å¨
            cout << "è¾å¥æ§å¶å¨åç§°ï¼" << endl;
            cin >> coary;
            cotempblock = (PCB *)malloc(sizeof(PCB));
            cotempblock->next = NULL;
            cotemp = (COCT *)malloc(sizeof(COCT));
            cotemp->next = NULL;
            strcpy(cotemp->identify, coary);
            cotemp->state = 0;
            cotemp->blocking = cotempblock;
            Addcotrol(cotemp);
            temp->coct = cotemp;
            cout << "è¯·éæ©è¿æ¥çéé:1/2" << endl; //å ä¸ºåªå®ä¹äºä¸¤ä¸ªééï¼é1å°±æ¯ch1ï¼é2å°±æ¯ch2
            int i;
            cin >> i;
            if (i == 1)
            {
                cotemp->chct = CH1;
            }
            else
            {
                cotemp->chct = CH2;
            }
        }
        else
        { //ä¸æ·»å æ§å¶å¨
            Showallco();
            cout << "è¾å¥è¿æ¥æ§å¶å¨çåç§°:" << endl;
            cin >> coary;
            cotemp = Findco(coary);
            temp->coct = cotemp;
        }
        cout << "è®¾å¤" << eqary << "æ·»å æå!" << endl;
    }
}
//å é¤è®¾å¤
void Deletedevice()
{ //å é¤è®¾å¤çæ¶ååæ¶å é¤pcb   Deletepcb
    cout << "å é¤è®¾å¤" << endl;
    COCT *temp;
    SDT *stemp;
    char chary[10];
    char tempary[10];
    cin >> chary;
    if (sf_exist(chary) == 0)
    {
        cout << "å é¤è®¾å¤ä¸å­å¨!" << endl;
    }
    else if (checkdel->dct->state == 1)
    {
        cout << "è®¾å¤æ­£å¨ä½¿ç¨æ æ³å é¤" << endl;
    }
    else
    { // sf_deleteco();
        Deletepcb(chary);
        strcpy(tempary, checkdel->dct->coct->identify);
        if (sf_deleteco(chary, tempary))
        { //å é¤æ§å¶å¨
            temp = checkdel->dct->coct;
            Deletecotrol(temp);
        }
        stemp = head;
        while (stemp->next != checkdel)
        {
            stemp = stemp->next;
        }
        stemp->next = checkdel->next;
        delete (checkdel);
        cout << "è®¾å¤" << chary << "å é¤æå!" << endl;
    }
}
//ç³è¯·è®¾å¤
void Applydevice()
{
    cout << "ç³è¯·è®¾å¤" << endl;
    PCB *ptemp;
    DCT *dtemp;
    COCT *cotemp;
    CHCT *chtemp;
    char pname[10], eqname[10];
    cout << "è¾å¥ç³è¯·è®¾å¤çè¿ç¨ï¼";
    cin >> pname;
    cout << "è¾å¥ç³è¯·çè®¾å¤åç§°ï¼";
    cin >> eqname;
    if (sf_exist(eqname) == 0)
    {
        cout << "è®¾å¤ä¸å­å¨!" << endl;
    }
    else
    { // checkdel(å¯¹åºè¦ç³è¯·è®¾å¤çæé)
        ptemp = (PCB *)malloc(sizeof(PCB));
        strcpy(ptemp->name, pname);
        ptemp->next = NULL;
        dtemp = checkdel->dct;
        //====================æ­¤å¤æ¯å¦è¦èèç¶æçæ¹å========================
        if (dtemp->state == 1)
        { //è®¾å¤å¿
            Addwaitpcb(dtemp->blocking, ptemp);
            cout << "è¿ç¨" << ptemp->name << "è¢«æå¨è®¾å¤" << dtemp->identify << "çç­å¾éåä¸!" << endl;
        }
        else
        { //è®¾å¤ä¸å¿
            cotemp = dtemp->coct;
            if (cotemp->state == 1)
            { //æ§å¶å¨å¿
                Addwaitpcb(cotemp->blocking, ptemp);
                cout << "è¿ç¨" << ptemp->name << "è¢«æå¨æ§å¶å¨" << cotemp->identify << "çç­å¾éåä¸!" << endl;
            }
            else
            { //æ§å¶å¨ä¸å¿
                chtemp = cotemp->chct;
                if (chtemp->state == 1)
                { //ééå¿
                    Addwaitpcb(chtemp->blocking, ptemp);
                    cout << "è¿ç¨" << ptemp->name << "è¢«æå¨éé" << chtemp->identify << "çç­å¾éåä¸!" << endl;
                }
                else
                { //ééä¸å¿
                    Addwaitpcb(run, ptemp);
                    dtemp->state = 1;
                    cotemp->state = 1;
                    chtemp->state = 1;
                    strcpy(ptemp->devname, eqname);
                    cout << "è¿ç¨" << pname << "ç³è¯·è®¾å¤" << eqname << "æå!" << endl;
                }
            }
        }
    }
}
//åæ¶è®¾å¤
void Recycledevice()
{
    cout << "åæ¶è®¾å¤" << endl;
    //	char ch;
    char eqname[10];
    DCT *dtemp;
    COCT *cotemp;
    CHCT *chtemp;
    PCB *pctemp1, *pctemp2;
    cin >> eqname;
    if (sf_exist(eqname) == 0)
    { //è®¾å¤ä¸å­å¨
        cout << "è¦åæ¶çè®¾å¤ä¸å­å¨!" << endl;
    }
    else if (checkdel->dct->state == 0)
    { //è®¾å¤å­å¨ï¼ä½æ¯ä¸éè¦åæ¶
        cout << "è®¾å¤å¤äºé²ç¶æï¼ä¸éè¦åæ¶!" << endl;
    }
    else
    {                      //éè¦åæ¶
        Deletepcb(eqname); //
        dtemp = checkdel->dct;
        cotemp = dtemp->coct;
        chtemp = cotemp->chct;
        dtemp->state = 0;
        cotemp->state = 0;
        chtemp->state = 0;
        if (sf_pcbnull(chtemp->blocking))
        { //å¦æééç­å¾éåä¸ç©º
            pctemp1 = chtemp->blocking;
            pctemp2 = pctemp1->next;
            pctemp1->next = pctemp2->next;
            pctemp2->next = NULL;
            strcpy(pctemp2->devname, eqname);
            Addwaitpcb(run, pctemp2);
            dtemp->state = 1;
            cotemp->state = 1;
            chtemp->state = 1;
        }
        else
        {
            if (sf_pcbnull(cotemp->blocking))
            { //å¦ææ§å¶å¨çç­å¾éåä¸ç©º
                pctemp1 = cotemp->blocking;
                pctemp2 = pctemp1->next;
                pctemp1->next = pctemp2->next;
                pctemp2->next = NULL;
                strcpy(pctemp2->devname, eqname);
                Addwaitpcb(run, pctemp2);
                dtemp->state = 1;
                cotemp->state = 1;
                chtemp->state = 1;
            }
            else
            {
                if (sf_pcbnull(dtemp->blocking))
                { //å¦æè®¾å¤çç­å¾éåä¸ç©º
                    pctemp1 = dtemp->blocking;
                    pctemp2 = pctemp1->next;
                    pctemp1->next = pctemp2->next;
                    pctemp2->next = NULL;
                    strcpy(pctemp2->devname, eqname);
                    Addwaitpcb(run, pctemp2);
                    dtemp->state = 1;
                    cotemp->state = 1;
                    chtemp->state = 1;
                }
            }
        }
        cout << "è®¾å¤" << eqname << "åæ¶æå!" << endl;
    }
}
//è®¾å¤ç¬ç«æ§=======
void Independence()
{
    cout << "è®¾å¤ç¬ç«æ§--ç³è¯·è®¾å¤:" << endl;
    // cout<<"ç³è¯·è®¾å¤"<<endl;
    char type;
    char pname[10];
    SDT *temp, *temp2;
    PCB *ptemp;
    DCT *dtemp;
    COCT *cotemp;
    CHCT *chtemp;
    cin >> pname >> type;
    if ((type == 'o') || (type == 'i'))
    { //=========è¿å¾èèè¦ç³è¯·çç±»åæ¯ä¸æ¯å­å¨============================
        if (sf_typeexist(type) == 0)
        {
            cout << "è¦ç³è¯·çè¯¥ç±»è®¾å¤ä¸å­å¨!" << endl;
        }
        else
        {
            temp = head->next;
            while (temp != NULL)
            {
                if ((temp->type == type) && (temp->dct->state == 0))
                { //å½è®¾å¤ç±»åç¸åï¼å¹¶ä¸è®¾å¤ç©ºé²
                    temp2 = temp;
                    break;
                }
                else if ((temp->type == type))
                {
                    temp2 = temp;
                }
                temp = temp->next;
            }
            sf_exist(temp2->identify); //=================================================
            ptemp = (PCB *)malloc(sizeof(PCB));
            strcpy(ptemp->name, pname);
            ptemp->next = NULL;
            dtemp = checkdel->dct; //è¦ç¨äºè¿ä¸ªå½æ°æå¯ä»¥==========================================================================
            if (temp2->dct->state == 0)
            { //å½è®¾å¤ä¸å¿æ¶å
                cotemp = dtemp->coct;
                if (cotemp->state == 1)
                { //æ§å¶å¨å¿
                    Addwaitpcb(cotemp->blocking, ptemp);
                    cout << "è¿ç¨" << ptemp->name << "è¢«æå¨æ§å¶å¨" << cotemp->identify << "çç­å¾éåä¸!" << endl;
                }
                else
                { //æ§å¶å¨ä¸å¿
                    chtemp = cotemp->chct;
                    if (chtemp->state == 1)
                    { //ééå¿
                        Addwaitpcb(chtemp->blocking, ptemp);
                        cout << "è¿ç¨" << ptemp->name << "è¢«æå¨éé" << chtemp->identify << "çç­å¾éåä¸!" << endl;
                    }
                    else
                    { //ééä¸å¿
                        Addwaitpcb(run, ptemp);
                        dtemp->state = 1;
                        cotemp->state = 1;
                        chtemp->state = 1;
                        strcpy(ptemp->devname, temp2->identify);
                        cout << "è¿ç¨" << pname << "ç³è¯·è®¾å¤" << temp2->identify << "æå!" << endl;
                    }
                }
            }
            else
            { //å½è®¾å¤å¿æ¶å
                Addwaitpcb(dtemp->blocking, ptemp);
                cout << "è¿ç¨" << ptemp->name << "è¢«æå¨è®¾å¤" << dtemp->identify << "çç­å¾éåä¸!" << endl;
            }
        }
    }
    else
    {
        cout << "è¾å¥è®¾å¤çç±»åéè¯¯!" << endl;
    }
}
//
void Show()
{
    cout << "A :å¢å è®¾å¤" << endl;
    cout << "D :å é¤è®¾å¤" << endl;
    cout << "S :ç³è¯·è®¾å¤" << endl;
    cout << "H :åæ¶è®¾å¤" << endl;
    cout << "I :è®¾å¤ç¬ç«æ§" << endl;
    cout << "Q :éåº" << endl;
}
//
int main()
{
    cout << "                   è®¾å¤ç®¡çå®éª          " << endl;
    cout << "                                           " << endl;
    cout << "ç¸å³æä»¤ï¼" << endl;
    Init();
    Show();
    char choice;
    while (true)
    {
        Showmenu();
        Show();
        cout << "éæ©æä»¤:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 'a':
        case 'A':
            Adddevice();
            break;
        case 'd':
        case 'D':
            Deletedevice();
            break;
        case 's':
        case 'S':
            Applydevice();
            break;
        case 'h':
        case 'H':
            Recycledevice();
            break;
        case 'q':
        case 'Q':
            exit(0);
        case 'i':
        case 'I':
            Independence();
            break;
        default:
            cout << "æä»¤éè¯¯" << endl;
            break;
        }
    }
    return 0;
}

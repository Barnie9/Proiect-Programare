
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct node {
    char marca[30], model[30], tip[30], culoare[30], numar[30];
    struct node* next;
};

struct list {
    struct node* head;
}l;

void printAll(struct list l)
{
    if (l.head)
    {
        struct node* current = l.head;
        while (current)
        {
            cout << endl << "Marca: " << current->marca << endl << "Model: " << current->model << endl << "Tip vehicul: " << current->tip << endl << "Culoare: " << current->culoare << endl << "Numar inmatriculare: " << current->numar << endl;
            // printf("\nMarca: %s\nModel: %s\nTip vehicul: %s\nCuloare: %s\nNumar inmatriculare: %s\n", current->marca, current->model, current->tip, current->culoare, current->numar);
            current = current->next;
        }
    }
    else
    {
        cout << endl << "Nu exista niciun autoturism in baza de date!" << endl;
        // printf("\nNu exista niciun autoturism in baza de date!\n");
    }
}

void writeInFile(struct list l)
{
    FILE* fl;
    fl = fopen("file.csv", "w");
    struct node* current;
    current = l.head;
    fprintf(fl, "Marca;Model;Tip;Culoare;Numar");
    while (current)
    {
        fprintf(fl, "\n%s;%s;%s;%s;%s", current->marca, current->model, current->tip, current->culoare, current->numar);
        current = current->next;
    }
    fclose(fl);
}

void appendWithText(struct list* l, char marca[], char model[], char tip[], char culoare[], char numar[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    strcpy(newNode->marca, marca);
    strcpy(newNode->model, model);
    strcpy(newNode->tip, tip);
    strcpy(newNode->culoare, culoare);
    strcpy(newNode->numar, numar);
    if (l->head == NULL)
        l->head = newNode;
    else
    {
        struct node* current = l->head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
    cout << endl << "Autoturismul a fost adaugat cu succes!" << endl;
    // printf("\nAutoturismul a fost adaugat cu succes!\n");
    writeInFile(*l);
}

void append(struct list* l, char marca[], char model[], char tip[], char culoare[], char numar[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    strcpy(newNode->marca, marca);
    strcpy(newNode->model, model);
    strcpy(newNode->tip, tip);
    strcpy(newNode->culoare, culoare);
    strcpy(newNode->numar, numar);
    if (l->head == NULL)
        l->head = newNode;
    else
    {
        struct node* current = l->head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
}

void search(struct list l, char numar[]) {
    struct node* current = l.head;
    while (current)
    {
        if (strcmp(current->numar, numar) == 0)
        {
            cout << endl << "Marca: " << current->marca << endl << "Model: " << current->model << endl << "Tip vehicul: " << current->tip << endl << "Culoare: " << current->culoare << endl << "Numar inmatriculare: " << current->numar << endl;
            // printf("\nMarca: %s\nModel: %s\nTip vehicul: %s\nCuloare: %s\nNumar inmatriculare: %s\n", current->marca, current->model, current->tip, current->culoare, current->numar);
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        cout << endl << "Autoturismul cu numarul de inmatriculare " << numar << " nu exista in baza de date!" << endl;
        // printf("\nAutoturismul cu numarul de inmatriculare %s nu exista in baza de date!\n", numar);
    }
}

void update(struct list* l, char marca[], char model[], char tip[], char culoare[], char numar[]) {
    struct node* current = l->head;
    while (current)
    {
        if (strcmp(current->numar, numar) == 0)
        {
            cout << endl << "Datele inainte de actualizare:";
            // printf("\nDatele inainte de actualizare:");
            search(*l, numar);
            if (strlen(marca) > 1)
                strcpy(current->marca, marca);
            if (strlen(model) > 1)
                strcpy(current->model, model);
            if (strlen(tip) > 1)
                strcpy(current->tip, tip);
            if (strlen(culoare) > 1)
                strcpy(current->culoare, culoare);
            cout << endl << "Datele dupa actualizare:";
            // printf("\nDatele dupa actualizare:");
            cout << endl << "Marca: " << current->marca << endl << "Model: " << current->model << endl << "Tip vehicul: " << current->tip << endl << "Culoare: " << current->culoare << endl << "Numar inmatriculare: " << current->numar << endl;
            // printf("\nMarca: %s\nModel: %s\nTip vehicul: %s\nCuloare: %s\nNumar inmatriculare: %s\n", current->marca, current->model, current->tip, current->culoare, current->numar);
            break;
        }
        current = current->next;
    }
    writeInFile(*l);
}

void delete_car(struct list* l, char numar[])
{
    struct node* current1 = l->head;
    if (strcmp(current1->numar, numar) == 0)
    {
        l->head = current1->next;
    }
    else
    {
        if (current1->next)
        {
            struct node* current2 = current1->next;
            while (current2)
            {
                if (strcmp(current2->numar, numar) == 0)
                {
                    current1->next = current2->next;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        else
        {
            if (strcmp(current1->numar, numar) == 0)
            {
                l->head = NULL;
            }
        }
    }
    cout << endl << "Autoturismul cu numarul de inmatriculare " << numar << " a fost sters!" << endl;
    // printf("\nAutoturismul cu numarul de inmatriculare %s a fost sters!\n", numar);
    writeInFile(*l);
}

void optiuni()
{
    cout << endl << "0 - Opreste executia";
    // printf("\n0 - Opreste executia");
    cout << endl << "1 - Vizualizeaza toate autoturismele";
    // printf("\n1 - Vizualizeaza toate autoturismele");
    cout << endl << "2 - Cauta un autoturism";
    // printf("\n2 - Cauta un autoturism");
    cout << endl << "3 - Adauga un autoturism";
    // printf("\n3 - Adauga un autoturism");
    cout << endl << "4 - Actualizeaza un autoturism";
    // printf("\n4 - Actualizeaza un autoturism");
    cout << endl << "5 - Sterge un autoturism";
    // printf("\n5 - Sterge un autoturism");
    cout << endl << "6 - Reaminteste-mi optiunile" << endl;
    // printf("\n6 - Reaminteste-mi optiunile\n");
}

int searchOnly(struct list l, char numar[]) {
    struct node* current = l.head;
    while (current)
    {
        if (strcmp(current->numar, numar) == 0)
            return 1;
        current = current->next;
    }
    return 0;
}

void appendFromFile(struct list* l)
{
    FILE* fl;
    fl = fopen("file.csv", "r");
    char marca[30], model[30], tip[30], culoare[30], numar[30];
    char line[500];
    fgets(line, 500, fl);
    while (fgets(line, 500, fl))
    {
        char* temp;
        temp = strtok(line, ";");
        strcpy(marca, temp);
        temp = strtok(NULL, ";");
        strcpy(model, temp);
        temp = strtok(NULL, ";");
        strcpy(tip, temp);
        temp = strtok(NULL, ";");
        strcpy(culoare, temp);
        temp = strtok(NULL, "\n");
        strcpy(numar, temp);
        append(l, marca, model, tip, culoare, numar);
    }
    fclose(fl);
}

int main() {

    appendFromFile(&l);

    cout << endl << "Buna ziua! Va rugam sa alegeti una dintre urmatoarele optiuni apasand tasta corespunzatoare si apoi enter:";
    // printf("\nBuna ziua! Va rugam sa alegeti una dintre urmatoarele optiuni apasand tasta corespunzatoare si apoi enter:");
    optiuni();

    int decizie, ok;
    char opt[100], temp;

    cout << endl << "Optiunea: ";
    // printf("\nOptiunea: ");
    cin >> opt;
    // scanf("%[^\n]", opt);
    while (strlen(opt) != 1)
    {
        cout << endl << "Optiunea: ";
        // printf("\nOptiunea: ");
        // scanf("%c",&temp);
        cin >> opt;
        // scanf("%[^\n]", opt);
    }
    decizie = opt[0] - '0';
    char marca[30], model[30], tip[30], culoare[30], numar[30], rsp[10];
    while (decizie)
    {
        switch (decizie)
        {
        case 1:
            printAll(l);
            break;
        case 2:
            cout << endl << "Introduceti numarul de inmatriculare al autoturismului cautat: ";
            // printf("\nIntroduceti numarul de inmatriculare al autoturismului cautat: ");
            cin.get();
            // scanf("%c",&temp);
            cin.getline(numar, 30);
            // scanf("%[^\n]", numar);
            for (int i = 0; i < strlen(numar); i++)
                numar[i] = toupper(numar[i]);
            search(l, numar);
            break;
        case 3:
            cout << endl << "Va rugam sa introduceti urmatoarele detalii: ";
            // printf("\nVa rugam sa introduceti urmatoarele detalii: ");
            cout << endl << "-> Marca autoturismului: ";
            // printf("\n-> Marca autoturismului: ");
            cin.get();
            // scanf("%c",&temp);
            cin.getline(marca, 30);
            // scanf("%[^\n]", marca);
            marca[0] = toupper(marca[0]);
            cout << "-> Modelul autoturismului: ";
            // printf("-> Modelul autoturismului: ");
            // scanf("%c",&temp);
            cin.getline(model, 30);
            // scanf("%[^\n]", model);
            model[0] = toupper(model[0]);
            cout << "-> Tipul autoturismului: ";
            // printf("-> Tipul autoturismului: ");
            // scanf("%c",&temp);
            cin.getline(tip, 30);
            // scanf("%[^\n]", tip);
            tip[0] = toupper(tip[0]);
            cout << "-> Culoarea autoturismului: ";
            // printf("-> Culoarea autoturismului: ");
            // scanf("%c",&temp);
            cin.getline(culoare, 30);
            // scanf("%[^\n]", culoare);
            culoare[0] = toupper(culoare[0]);
            cout << "-> Numarul de inmatriculare al autoturismului: ";
            // printf("-> Numarul de inmatriculare al autoturismului: ");
            // scanf("%c",&temp);
            cin.getline(numar, 30);
            // scanf("%[^\n]", numar);
            for (int i = 0; i < strlen(numar); i++)
                numar[i] = toupper(numar[i]);
            appendWithText(&l, marca, model, tip, culoare, numar);
            break;
        case 4:
            cout << endl << "Introduceti numarul de inmatriculare al autoturismului care trebuie actualizat: ";
            // printf("\nIntroduceti numarul de inmatriculare al autoturismului care trebuie actualizat: ");
            cin.get();
            // scanf("%c",&temp);
            cin.getline(numar, 30);
            // scanf("%[^\n]", numar);
            for (int i = 0; i < strlen(numar); i++)
                numar[i] = toupper(numar[i]);
            ok = 1;
            while (searchOnly(l, numar) == 0)
            {
                cout << endl << "Autoturismul cu numarul de inmatriculare " << numar << " nu exista in baza de date!";
                // printf("\nAutoturismul cu numarul de inmatriculare %s nu exista in baza de date!", numar);
                cout << endl << "Doriti sa cautati alt autoturism? (DA/NU)" << endl;
                // printf("\nDoriti sa cautati alt autoturism? (DA/NU)\n");
                // scanf("%c",&temp);
                cin.getline(rsp, 10);
                // scanf("%[^\n]", &rsp);
                if (stricmp(rsp, "da") == 0)
                {
                    cout << endl << "Va rugam sa introduceti alt numar de inmatriculare: ";
                    // printf("\nVa rugam sa introduceti alt numar de inmatriculare: ");
                    // scanf("%c",&temp);
                    cin.getline(numar, 30);
                    // scanf("%[^\n]", numar);
                    for (int i = 0; i < strlen(numar); i++)
                        numar[i] = toupper(numar[i]);
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << endl << "Va rugam sa introduceti urmatoarele detalii: (daca nu doriti ca respectivul camp sa fie actualizat, lasati un '-')";
                //printf("\nVa rugam sa introduceti urmatoarele detalii: (daca nu doriti ca respectivul camp sa fie actualizat, lasati un '-')");
                cout << endl << "-> Marca autoturismului: ";
                // printf("\n-> Marca autoturismului: ");
                cin.get();
                // scanf("%c",&temp);
                cin.getline(marca, 30);
                // scanf("%[^\n]", marca);
                marca[0] = toupper(marca[0]);
                cout << "-> Modelul autoturismului: ";
                // printf("-> Modelul autoturismului: ");
                // scanf("%c",&temp);
                cin.getline(model, 30);
                // scanf("%[^\n]", model);
                model[0] = toupper(model[0]);
                cout << "-> Tipul autoturismului: ";
                // printf("-> Tipul autoturismului: ");
                // scanf("%c",&temp);
                cin.getline(tip, 30);
                // scanf("%[^\n]", tip);
                tip[0] = toupper(tip[0]);
                cout << "-> Culoarea autoturismului: ";
                // printf("-> Culoarea autoturismului: ");
                // scanf("%c",&temp);
                cin.getline(culoare, 30);
                // scanf("%[^\n]", culoare);
                culoare[0] = toupper(culoare[0]);
                update(&l, marca, model, tip, culoare, numar);
            }
            break;
        case 5:
            cout << endl << "Introduceti numarul de inmatriculare al autoturismului care trebuie sters: ";
            // printf("\nIntroduceti numarul de inmatriculare al autoturismului care trebuie sters: ");
            cin.get();
            // scanf("%c",&temp);
            cin.getline(numar, 30);
            // scanf("%[^\n]", numar);
            for (int i = 0; i < strlen(numar); i++)
                numar[i] = toupper(numar[i]);
            ok = 1;
            while (searchOnly(l, numar) == 0)
            {
                cout << endl << "Autoturismul cu numarul de inmatriculare " << numar << " nu exista in baza de date!";
                // printf("\nAutoturismul cu numarul de inmatriculare %s nu exista in baza de date!", numar);
                cout << endl << "Doriti sa stergeti alt autoturism? (DA/NU)" << endl;
                // printf("\nDoriti sa stergeti alt autoturism? (DA/NU)\n");
                // scanf("%c",&temp);
                cin.getline(rsp, 10);
                // scanf("%[^\n]", &rsp);
                if (stricmp(rsp, "da") == 0)
                {
                    cout << endl << "Va rugam sa introduceti alt numar de inmatriculare: ";
                    // printf("\nVa rugam sa introduceti alt numar de inmatriculare: ");
                    // scanf("%c",&temp);
                    cin.getline(numar, 30);
                    // scanf("%[^\n]", numar);
                    for (int i = 0; i < strlen(numar); i++)
                        numar[i] = toupper(numar[i]);
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                delete_car(&l, numar);
            break;
        case 6:
            optiuni();
            break;
        }
        cout << endl << "Optiunea: ";
        // printf("\nOptiunea: ");
        cin >> opt;
        // scanf("%[^\n]", opt);
        while (strlen(opt) != 1)
        {
            cout << endl << "Optiunea: ";
            // printf("\nOptiunea: ");
            // scanf("%c",&temp);
            cin >> opt;
            // scanf("%[^\n]", opt);
        }
        decizie = opt[0] - '0';
    }
    cout << endl << "Oprirea executiei!";
    // printf("\nOprirea executiei!");

    writeInFile(l);

    return 0;
}

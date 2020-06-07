#include "headers/Menu.h"
void menu(Head *ddd)
{
    int k;
    inform_menu();
    /*scanf("%d", &k);
    if(k < 0 || k > 7)
    {
        while((k < 0)||(k > 7)){
            printf("\nPlease enter correct choice!\n>");
            scanf("%d", &k);
        }
    }*/
    k = correct(ddd, 0, 8);
    switch(k)
    {
    case 0:
        case0(ddd);
        break;
    case 1:
        case1(ddd);
        break;
    case 2:
        case2(ddd);
        break;
    case 3:
        case3(ddd);
        break;
    case 4:
        case4(ddd);
        break;
    case 5:
        case5(ddd);
        break;
    case 6:
        case6(ddd);
        break;
    case 7:
        case7(ddd);
        break;
    case 8:
        printf("Bye-bye\nPress enter!\n");
        getch();
        free_list(ddd);
        exit(EXIT_SUCCESS);
    }
}

void inform_menu()
{
    system("cls");
    printf("0. Reference\n");
    printf("1. Add structure\n");
    printf("2. Edit structure\n");
    printf("3. Delete structure\n");
    printf("4. Structure inference\n");
    printf("5. Parameter structure search\n");
    printf("6. Sort structures by a specific parameter\n");
    printf("7. Write current list to file\n");
    printf("8. Exit\n");
    printf("\nEnter your choice:\n>");
}

void case0(Head *ddd)
{
    system("cls");
    printf("This program was developed to work with some data.\n");
    printf("It gets the information about animals from file and creates an array of structures.\n");
    printf("This array can be edited in a certain ways: it is possible to delete items, change features of items and add items.\n");
    printf("For more comfortable perception of presented information this program also allows user to search items.\n");
    printf("Sorting items by some feature is included as well.\n");
    printf("All of the actions can be done multiple times.\n");
    printf("Created by student of group 9305 Lyubanevich Roman\n");
    back_to_menu(ddd);
}
void case4(Head *ddd)
{
    system("cls");
    int choice;
    printf("How do you want to see the list?\n1.Upright\n2.Upside down\nEnter your choice!\n>");
    choice = correct(ddd, 1, 2);
    /*scanf("%d", &choice);
    if(choice != 1 && choice != 2)
    {
        while((choice != 1)&&(choice != 2)){
            printf("\nPlease enter correct choice!\n>");
            scanf("%d", &choice);
        }
    }*/
    system("cls");
    if (choice == 1)
        node_out(ddd);
    else if (choice == 2)
        node_out_reverse(ddd);
    back_to_menu(ddd);
}

void case1(Head *ddd)
{
    int choice;
    system("cls");
    printf("Where do you want to insert the structure?\n1.First\n2.Last\n>");
    choice = correct(ddd, 1, 2);
    if (choice == 1)
        add_first(ddd);
    else if (choice == 2)
           add_last(ddd);
    back_to_menu(ddd);
}

void back_to_menu(Head *ddd)
{
    int choice;
    printf("\nBack to menu?\n1.Yes\n2.No(exit)\n>");
    choice = correct(ddd, 1, 2);
    if (choice == 1)
        menu(ddd);
    else if (choice == 2)
    {
        printf("\nBye-bye\nPress enter!\n");
        getch();
        free_list(ddd);
        exit(EXIT_SUCCESS);
    }
}

int correct(Head *ddd, int a, int b)
{
    int choice;
    scanf("%d", &choice);
    if(choice < a || choice > b)
    {
        while((choice < a)||(choice > b)){
            printf("\nPlease enter correct choice!\n>");
            scanf("%d", &choice);
        }
    }
    return choice;
}

void case3(Head *ddd)
{
    int choice, n;
    n = ddd->cnt;
    system("cls");
    printf("What structure should be removed?\n>");
    choice = correct(ddd, 1, n);
    delete_node(ddd, choice);
    back_to_menu(ddd);
}

void case2(Head *ddd)
{
    int choice, n, ch1;
    n = ddd -> cnt;
    system("cls");
    printf("What structure should be edit?\n>");
    choice = correct(ddd, 1, n);
    printf("\nWhat exactly needs to be changed in the structure?\n1.Name\n2.Kind\n3.Lifespan\n4.Weight\n5.Height\n>");
    ch1 = correct(ddd, 1, 5);
    edit_structure(ddd, choice, ch1);
    back_to_menu(ddd);
}

void case5(Head *ddd)
{
    int choice;
    system("cls");
    printf("What exactly needs to be find in the structure?\n1.Name\n2.Kind\n3.Lifespan\n4.Weight\n5.Height\n>");
    choice = correct(ddd, 1, 5);
    switch(choice)
    {
    case 1:
        find_name(ddd);
        break;
    case 2:
        find_kind(ddd);
        break;
    case 3:
        find_lifespan(ddd);
        break;
    case 4:
        find_weight(ddd);
        break;
    case 5:
        find_height(ddd);
        break;
    }
    back_to_menu(ddd);
}

void case6(Head *ddd)
{
    int choice;
    system("cls");
    printf("\nHow you wanna sort structures? By:\n1.Lifespan\n2.Weight\n3.Height\n>");
    choice = correct(ddd, 1, 3);
    switch(choice)
    {
    case 1:
        sort_by_lifespan(ddd);
        break;
    case 2:
        sort_by_weight(ddd);
        break;
    case 3:
        sort_by_height(ddd);
        break;
    }
    back_to_menu(ddd);
}

void case7(Head *ddd)
{
    FILE *mf;
    mf = fopen("res.txt", "w");
    system("cls");
    Node *temp = ddd -> first;
    while (temp != NULL)
    {
        fprintf(mf, "| %9s |%10s |%8d |%10f |%10f |\n",
            temp -> structure -> name, temp -> structure -> kind, temp -> structure ->  lifespan, temp -> structure ->  characteristic[0], temp -> structure ->  characteristic[1]);
        temp = temp -> next;
    }
    puts("List was current to file!");
    back_to_menu(ddd);

}

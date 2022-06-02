//KingOfMongeese
//A scoring program that is a CLI version of Agricola Scoreboard that I had written in python. Now written in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{   
    //init values
    char s_num_fields[10], s_num_pastures[10], s_num_grain[10], s_num_veg[10], s_num_sheep[10], s_num_boar[10], s_num_cattle[10];
    int fields_pts, pastures_pts, grain_pts, veg_pts, sheep_pts, boar_pts, cattle_pts;
    int num_fields, num_pastures, num_grain, num_veg, num_sheep, num_boar, num_cattle;

    //getting input safely
    printf("Enter the number of fields\n>");

    fgets(s_num_fields, sizeof(s_num_fields), stdin);
    if (s_num_fields[strlen(s_num_fields) - 1] != '\n')
    {   
        //clear input buffer
        int b;
        while (b = getchar() != '\n' && b != EOF ){}
    }

    printf("Enter the number of pastures\n>");

    fgets(s_num_pastures, sizeof(s_num_pastures), stdin);
    if(s_num_pastures[strlen(s_num_pastures) - 1 ] != '\n')
    {
        int b;
        while (b = getchar() != '\n' && b != EOF ){}
    }

    printf("Enter the number of grain\n>");

    fgets(s_num_grain, sizeof(s_num_grain), stdin);
    if (s_num_grain[strlen(s_num_grain) - 1] != '\n')
    {
        int b; 
        while(b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of vegetables\n>");

    fgets(s_num_veg, sizeof(s_num_veg), stdin);
    if(s_num_veg[strlen(s_num_veg) - 1 ]  != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}

    }

    printf("Enter the number of sheep\n>");

    fgets(s_num_sheep, sizeof(s_num_sheep), stdin);
    if(s_num_sheep[strlen(s_num_sheep) - 1] != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}
        
    }

    printf("Enter the number of boars\n>");
    fgets(s_num_boar, sizeof(s_num_boar), stdin);
    if (s_num_boar[strlen(s_num_boar) - 1] != '\n')
    { 
        int b;
        while(b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of cattle\n>");
    fgets(s_num_cattle, sizeof(s_num_cattle), stdin);
    if(s_num_cattle[strlen(s_num_cattle) - 1] != '\n')
    {
        int b;
        while (b = getchar() != '\n' && b != EOF){}
    }

    //converting string to long int
    num_fields = strtol(s_num_fields, NULL, 10);
    num_pastures = strtol(s_num_pastures, NULL, 10);
    num_grain = strtol(s_num_grain, NULL, 10);
    num_veg = strtol(s_num_veg, NULL, 10);
    num_sheep = strtol(s_num_sheep, NULL, 10);
    num_boar = strtol(s_num_boar, NULL, 10);
    num_cattle = strtol(s_num_cattle, NULL, 10);

    //fields
    if (num_fields <= 1)
    {
        fields_pts = -1;
    }
    else if (num_fields == 2)
    {
        fields_pts = 1;
    }
    else if (num_fields == 3) 
    {
        fields_pts = 2;
    }
    else if (num_fields == 4)
    {
        fields_pts = 3;
    }
    else if ( num_fields >= 5 )
    {
        fields_pts = 4;
    }

    //pastures
    pastures_pts = num_pastures;
    if (pastures_pts > 4 )
    {
        pastures_pts = 4;
    } 
    else if (pastures_pts <= 0)
    {
        pastures_pts = -1;
    }

    //grain
    if (num_grain <= 0 )
    {
        grain_pts = -1;
    }
    else if (num_grain >= 1 && num_grain <= 3)
    {
        grain_pts = 1;
    }
    else if (num_grain == 4 || num_grain == 5)
    {
        grain_pts = 2;
    }
    else if (num_grain == 6 || num_grain == 7)
    {
        grain_pts = 3;
    }
    else if(num_grain >= 8)
    {
        grain_pts = 4;
    }

    //vegies
    veg_pts = num_veg;
    if(veg_pts > 4 )
    {
        veg_pts = 4;
    }
    else if (veg_pts <= 0)
    {
        veg_pts = -1;
    }

    //sheep
    if (num_sheep <= 0)
    {
        sheep_pts = -1;
    }
    else if (num_sheep >= 1 && num_sheep <= 3)
    {
        sheep_pts = 1;
    }
    else if (num_sheep == 4 || num_sheep == 5)
    {
        sheep_pts = 2;
    }
    else if (num_sheep == 6 || num_sheep == 7)
    {
        sheep_pts = 3;
    }
    else if (num_sheep >= 8)
    {
        sheep_pts = 4;
    }

    //boar
    if (num_boar <= 0)
    {
        boar_pts = -1;
    }
    else if (num_boar == 1 || num_boar == 2)
    {
        boar_pts = 1;
    }
    else if (num_boar == 3 || num_boar == 4)
    {
        boar_pts = 2;
    }
    else if (num_boar == 5 || num_boar == 6)
    {
        boar_pts = 3;
    }
    else if (num_boar >= 0)
    {
        boar_pts = 4;
    }

    //cattle
    if (num_cattle <= 0)
    {
        cattle_pts = -1;
    }
    else if (num_cattle == 1)
    {
        cattle_pts = 1;
    }
    else if (num_cattle == 2 || num_cattle == 3)
    {
        cattle_pts = 2;
    }
    else if (num_cattle == 4 || num_cattle == 5)
    {
        cattle_pts = 3;
    }
    else if (cattle_pts >= 8)
    {
        cattle_pts = 4;
    }

    //get other input

    char s_unused_space[10], s_fenced_stables[10], s_stone_room[10], s_family_mem[10], s_bonus[10], s_num_beg[10];
    int num_stone, num_family, num_beg;
    int spaces_pts, stables_pts_clay, stone_pts, family_pts, bonus_pts, beg_pts;

    printf("Enter the number of unused spaces\n>");

    fgets(s_unused_space, sizeof(s_unused_space), stdin);
    if (s_unused_space[strlen(s_unused_space) - 1] != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of fenced stables and clay hut rooms\n>");
    fgets(s_fenced_stables, sizeof(s_fenced_stables), stdin);
    if (s_fenced_stables[strlen(s_fenced_stables) - 1] != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of stone rooms\n>");
    fgets(s_stone_room, sizeof(s_stone_room), stdin);
    if (s_stone_room[strlen(s_stone_room) - 1] != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of family members\n>");
    fgets(s_family_mem, sizeof(s_family_mem), stdin);
    if (s_family_mem[strlen(s_family_mem) - 1] != '\n')
    {
        int b;
        while (b = getchar() != '\n' && b != EOF){}
    } 

    printf("Enter the number of points from bonus cards\n>");
    fgets(s_bonus, sizeof(s_bonus), stdin);
    if(s_bonus[strlen(s_bonus) - 1 ] != '\n')
    {
        int b; 
        while (b = getchar() != '\n' && b != EOF){}
    }

    printf("Enter the number of begging cards\n>");
    fgets(s_num_beg, sizeof(s_num_beg), stdin);
    if(s_num_beg[strlen(s_num_beg) - 1] != '\n')
    {
        int b;
        while(b = getchar() != '\n' && b != EOF){}
    }

    
    int num_spaces = strtol(s_unused_space, NULL, 10);
    stables_pts_clay = strtol(s_fenced_stables, NULL, 10);
    num_stone = strtol(s_stone_room, NULL, 10);
    num_family = strtol(s_family_mem, NULL, 10);
    bonus_pts = strtol(s_bonus, NULL, 10);
    num_beg = strtol(s_num_beg, NULL, 10);

    if (spaces_pts < 0)
    {
        spaces_pts = 0;
    }
    if (stables_pts_clay < 0)
    {
        stables_pts_clay = 0;
    }
    

    
    family_pts = num_family * 3;
    stone_pts = num_stone * 2;
    beg_pts = num_beg * -3;
    spaces_pts = -(num_spaces);


    int total;

    total = fields_pts + pastures_pts + grain_pts + veg_pts + sheep_pts + boar_pts + cattle_pts + stables_pts_clay + stone_pts + family_pts + beg_pts + bonus_pts + spaces_pts;

    printf("        %10s|%10s|%10s|%10s|%10s|%10s|%10s|%15s|%15s|%10s|%15s|%10s|%15s\n", "Fields", "Pastures", "Grain", "Vegies", "Sheep", "Boar", "Cattle", "Stable/Clay", "Stone Rooms", "Family", "Begging Cards", "Bonus", "Unused Spaces" );
    printf("Entered %10d|%10d|%10d|%10d|%10d|%10d|%10d|%15d|%15d|%10d|%15d|%10d|%15d\n", num_fields, num_pastures, num_grain, num_veg, num_sheep, num_boar, num_cattle, stables_pts_clay, num_stone, num_family, num_beg, bonus_pts, num_spaces);
    printf("Points  %10d|%10d|%10d|%10d|%10d|%10d|%10d|%15d|%15d|%10d|%15d|%10d|%15d\n", fields_pts, pastures_pts, grain_pts, veg_pts, sheep_pts, boar_pts, cattle_pts, stables_pts_clay, stone_pts, family_pts, beg_pts, bonus_pts, spaces_pts);
    printf("Total: %d\n", total);


    



    return 0;
}


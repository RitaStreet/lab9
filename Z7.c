//SUB_ZZ_Z
//Любаневич Роман 9305
//Вычитание целых чисел
//Из первого параметра вычитаем второй

integer *Z7(integer *A, integer *B)
{
    int k;
    integer *R;
    natural *A1, *B1, *L;

    if (Z2(A) == 0)
    {
        if (Z2(B) == 2)
            B -> sign = false;
        else if (Z2(B) == 1)
            B -> sign = true;
        return(B);
    }

    if (Z2(B) == 0)
        return(A);

    if (Z2(A) == 1 && Z2(B) == 1)
    {
        A -> sign = true;
        B -> sign = true;
        A1 = Z5(A);
        B1 = Z5(B);
        L = N4(A1, B1);
        R = Z4(L);
        R -> sign = false;
        return(R);
    }

    if (Z2(A) == 2 && Z2(B) == 1)
    {
        A1 = Z5(A);
        B -> sign = true;
        B1 = Z5(B);
        L = N4(A1, B1);
        R = Z4(L);
        return(R);
    }

    if (Z2(A) == 2 && Z2(B) == 2)
    {
        A1 = Z5(A);
        B1 = Z5(B);
        k = N1(A1, B1)
        if (k == 2 || k == 0)
        {
            L = N5(A1, B1);
            R = Z4(L);
            return(R);
        }
        else
        {
            L = N5(B1, A1);
            R = Z4(L)
            R -> sign = false;
            return(R);
        }
    }

    if (Z2(A) == 1 && Z2(B) == 2)
    {
        B1 = Z5(B);
        A -> sign = true;
        A1 = Z5(A);
        L = N4(A1, B1);
        R = Z4(L);
        R -> sign = false;
        return(R);
    }

}

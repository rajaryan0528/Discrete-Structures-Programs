
//This the header file containing the functions defined in q3.cpp
// s is the cardinality of the set in which the relation is defined
//arr is the matrix representation of the relation
bool isTransitive(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < s; k++)

                if ((*(arr + i * s + j) == 1) && (*(arr + j * s + k) == 1) && (*(arr + i * s + k) != 1))
                    return  false;
        }
    }
    return true;
}

bool isReflexive(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + i) != 1))
                       return false;
        }
    }

    return true;;
}

bool isSymmetric(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + j) == 1) && (*(arr + j * s + i) != 1))
                return false;
        }
    }

    return true;
}

bool isAntiSymmetric(int *arr, int s)
{
    bool yes = true;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if ((*(arr + i * s + j) == 1) & (*(arr + j * s + i) != 1))
                yes = true;
            else if (i == j)
                yes = true;
            else
                yes = false;
        }
    }

    if(yes==true)
       return true;
    else
      return false;
}


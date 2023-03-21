#include <windows.h>
#include <direct.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#define BUFSIZE MAX_PATH

#define FILESYSNAMEBUFSIZE MAX_PATH
#define _WIN32_WINNT 0x0501



// использование двумерных массивов для хранения строк диска

char drive2[13][5] = { "A:\\", "B:\\", "C:\\", "D:\\", "E:\\", "F:\\", "G:\\", "H:\\","I:\\", "J:\\", "K:\\", "L:\\" };

TCHAR szDrive[] = _T(" A:");

// длина буфера

DWORD mydrives = 100;

// буфер для хранения строки привода

char lpBuffer[100];

// запросите их на моем компьютере. L: - это флэш-накопитель, J: и K: - компакт-диски

char lpDeviceName[11][3] = { "A:", "C:", "D:", "E:", "F:", "G:", "H:","I:", "J:", "K:", "L:" };

// буфер для хранения

char lpTargetPath[1000];



int main()

{
    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < 12; i++)

    {

        UINT test = GetDriveType(drive2[i]);

        switch (test)

        {

        case 0: printf("Привод %s имеет тип %d - не может быть определен.\n", &drive2[i], test);

            break;

        case 1: printf("Диск %s имеет тип %d - недопустимый корневой путь/Недоступен.\n", &drive2[i], test);

            break;

        case 2: printf("Привод %s относится к типу %d - съемный.\n", &drive2[i], test);

            break;

        case 3: printf("Привод %s имеет тип %d - фиксированный.\n", &drive2[i], test);

            break;

        case 4: printf("Диск % s - это тип % d - Network.\n", &drive2[i], test);

            break;

        case 5: printf("Привод %s имеет тип %d - CD-ROM.\n", &drive2[i], test);

            break;

        case 6: printf("Диск %s имеет тип %d - RAMDISK.\n", &drive2[i], test);

            break;

        default: "Неизвестное значение!\n";

        }
        DWORD uDriveMask = GetLogicalDrives();

        printf("Битовая маска логических дисков в шестнадцатеричном формате: %0X\n", uDriveMask);

        printf("Битовая маска логических дисков в десятичной системе счисления: %d\n", uDriveMask);

        if (uDriveMask == 0)

            printf("Ошибка GetLogicalDrives() с кодом сбоя : % d\n", GetLastError());

        else

        {

            printf("Эта машина имеет следующие логические диски:\n");

            while (uDriveMask)

            {// используйте побитовое И, 1–доступно, 0-недоступно

                if (uDriveMask & 1)

                    printf(szDrive);

                // прирост...

                ++szDrive[1];

                // сдвиньте двоичную битовую маску вправо

                uDriveMask >>= 1;

            }

            printf("\n ");

        }
    }
        DWORD test = GetLogicalDriveStrings(mydrives, lpBuffer);

        printf("GetLogicalDriveStrings() возвращает значение: %d\ Ошибка: %d \n", test, GetLastError());

        printf("Логическими дисками этой машины являются:\n");

    for (int i = 0; i < 100; i++)

            printf("%c", lpBuffer[i]);

        printf("\n");

        printf("\n");

        int second();
        {
            char pszDrive[10] =  "C:\\";

            // 64-битное целое число

            __int64 lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes;

            DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
            BOOL test = GetDiskFreeSpaceEx(pszDrive,

                (PULARGE_INTEGER)&lpFreeBytesAvailable,

                (PULARGE_INTEGER)&lpTotalNumberOfBytes,

                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes);



            printf("Диск, подлежащий проверке: %s\n", pszDrive);

            printf("\nИспользуя GetDiskFreeSpaceEx()...\n");

            // проверьте возвращаемое значение

            printf("Возвращаемое значение: %d, код ошибки: %d\n", test, GetLastError());

            printf("Общее количество свободных байт, доступных для вызывающего пользователя: %ul\n", lpFreeBytesAvailable);

            printf("Общее количество байтов, доступных пользователю: %ul\n", lpTotalNumberOfBytes);

            // просто сразу к результату свободных байтов

            printf("Общее количество свободных байт на диске: %ul\n", lpTotalNumberOfFreeBytes);



            BOOL fResult = GetDiskFreeSpace(pszDrive, &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);



            printf("\nИспользуя GetDiskFreeSpace()...\n");

            printf("Возвращаемое значение: %d, код ошибки: %d\n", fResult, GetLastError());

            printf("Сектор на кластер = %ul\n", dwSectPerClust);

            printf("Байт на сектор = %ul\n", dwBytesPerSect);

            printf("Свободный кластер = %ul\n", dwFreeClusters);

            printf("Общий кластер = %ul\n", dwTotalClusters);

            // при использовании GetDiskFreeSpace() требуется некоторое вычисление свободных байт на диске

            printf("Общее количество свободных байт = %ul\n", (dwFreeClusters * dwSectPerClust * dwBytesPerSect));

            return 0;

           BOOL GetVolumeInformation(
               LPCTSTR lpRootPathName, 
                LPTSTR lpVolumeNameBuffer, 
                DWORD nVolumeNameSize, 
                LPDWORD lpVolumeSerialNumber, 
                LPDWORD lpMaximumComponentLength, 
                LPDWORD lpFileSystemFlags,
                LPTSTR lpFileSystemNameBuffer, 
                DWORD nFileSystemNameSize 
                      
            );

        }
        

    return 0;

}



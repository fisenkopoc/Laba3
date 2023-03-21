#include <windows.h>
#include <direct.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#define BUFSIZE MAX_PATH

#define FILESYSNAMEBUFSIZE MAX_PATH
#define _WIN32_WINNT 0x0501



// ������������� ��������� �������� ��� �������� ����� �����

char drive2[13][5] = { "A:\\", "B:\\", "C:\\", "D:\\", "E:\\", "F:\\", "G:\\", "H:\\","I:\\", "J:\\", "K:\\", "L:\\" };

TCHAR szDrive[] = _T(" A:");

// ����� ������

DWORD mydrives = 100;

// ����� ��� �������� ������ �������

char lpBuffer[100];

// ��������� �� �� ���� ����������. L: - ��� ����-����������, J: � K: - �������-�����

char lpDeviceName[11][3] = { "A:", "C:", "D:", "E:", "F:", "G:", "H:","I:", "J:", "K:", "L:" };

// ����� ��� ��������

char lpTargetPath[1000];



int main()

{
    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < 12; i++)

    {

        UINT test = GetDriveType(drive2[i]);

        switch (test)

        {

        case 0: printf("������ %s ����� ��� %d - �� ����� ���� ���������.\n", &drive2[i], test);

            break;

        case 1: printf("���� %s ����� ��� %d - ������������ �������� ����/����������.\n", &drive2[i], test);

            break;

        case 2: printf("������ %s ��������� � ���� %d - �������.\n", &drive2[i], test);

            break;

        case 3: printf("������ %s ����� ��� %d - �������������.\n", &drive2[i], test);

            break;

        case 4: printf("���� % s - ��� ��� % d - Network.\n", &drive2[i], test);

            break;

        case 5: printf("������ %s ����� ��� %d - CD-ROM.\n", &drive2[i], test);

            break;

        case 6: printf("���� %s ����� ��� %d - RAMDISK.\n", &drive2[i], test);

            break;

        default: "����������� ��������!\n";

        }
        DWORD uDriveMask = GetLogicalDrives();

        printf("������� ����� ���������� ������ � ����������������� �������: %0X\n", uDriveMask);

        printf("������� ����� ���������� ������ � ���������� ������� ���������: %d\n", uDriveMask);

        if (uDriveMask == 0)

            printf("������ GetLogicalDrives() � ����� ���� : % d\n", GetLastError());

        else

        {

            printf("��� ������ ����� ��������� ���������� �����:\n");

            while (uDriveMask)

            {// ����������� ��������� �, 1���������, 0-����������

                if (uDriveMask & 1)

                    printf(szDrive);

                // �������...

                ++szDrive[1];

                // �������� �������� ������� ����� ������

                uDriveMask >>= 1;

            }

            printf("\n ");

        }
    }
        DWORD test = GetLogicalDriveStrings(mydrives, lpBuffer);

        printf("GetLogicalDriveStrings() ���������� ��������: %d\ ������: %d \n", test, GetLastError());

        printf("����������� ������� ���� ������ ��������:\n");

    for (int i = 0; i < 100; i++)

            printf("%c", lpBuffer[i]);

        printf("\n");

        printf("\n");

        int second();
        {
            char pszDrive[10] =  "C:\\";

            // 64-������ ����� �����

            __int64 lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes;

            DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
            BOOL test = GetDiskFreeSpaceEx(pszDrive,

                (PULARGE_INTEGER)&lpFreeBytesAvailable,

                (PULARGE_INTEGER)&lpTotalNumberOfBytes,

                (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes);



            printf("����, ���������� ��������: %s\n", pszDrive);

            printf("\n��������� GetDiskFreeSpaceEx()...\n");

            // ��������� ������������ ��������

            printf("������������ ��������: %d, ��� ������: %d\n", test, GetLastError());

            printf("����� ���������� ��������� ����, ��������� ��� ����������� ������������: %ul\n", lpFreeBytesAvailable);

            printf("����� ���������� ������, ��������� ������������: %ul\n", lpTotalNumberOfBytes);

            // ������ ����� � ���������� ��������� ������

            printf("����� ���������� ��������� ���� �� �����: %ul\n", lpTotalNumberOfFreeBytes);



            BOOL fResult = GetDiskFreeSpace(pszDrive, &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);



            printf("\n��������� GetDiskFreeSpace()...\n");

            printf("������������ ��������: %d, ��� ������: %d\n", fResult, GetLastError());

            printf("������ �� ������� = %ul\n", dwSectPerClust);

            printf("���� �� ������ = %ul\n", dwBytesPerSect);

            printf("��������� ������� = %ul\n", dwFreeClusters);

            printf("����� ������� = %ul\n", dwTotalClusters);

            // ��� ������������� GetDiskFreeSpace() ��������� ��������� ���������� ��������� ���� �� �����

            printf("����� ���������� ��������� ���� = %ul\n", (dwFreeClusters * dwSectPerClust * dwBytesPerSect));

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



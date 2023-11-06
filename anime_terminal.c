#include <stdio.h>
#include <unistd.h>
#include<windows.h>
#include<dirent.h>
int show_img(char* path) {
    FILE *file;
    char line[1000]; // 每行最多100個字符

    // 打開文件
    file = fopen(path, "r");

    if (file == NULL) {
        printf("无法打开文件\n");
        return 1;
    }

    // 逐行讀取
    while (fgets(line, sizeof(line), file) != NULL) printf("%s", line);

    // 關閉文件
    fclose(file);

    return 0;
}

int main() {


    char ch;
    while((ch = getch()) != ' ');

    for (int t = 0;t < 10;t++){
        char dir_path[] = "txt";
        DIR* dir = opendir(dir_path);
        struct dirent* entry;

        int count = -1;
        while((entry = readdir(dir)) != NULL){
            count++;
            if (count <= 1) continue;//前兩個是.和..

            char txt_path[40] = "txt\\";//儲存文字檔與這個C執行檔的相對路徑
            int i = 0, j = 4;//i是檔案名稱字串的index, j是txt_path的index
            while (1){
                txt_path[j] = (entry -> d_name)[i];
                if (i - 3 > 0 && (entry -> d_name)[i] == 't' && (entry -> d_name)[i - 3] == '.') break;//確定找到.txt就break
                i++, j++;
            }
            txt_path[j + 1] = '\0';

            printf("\033[H"); // 將光標移動到螢幕左上角
            show_img(txt_path);
            fflush(stdout);

            usleep(21150); // 1e-6s


        }
    }





    return 0;

}


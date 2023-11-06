# terminal_anime


https://github.com/weiso131/terminal_anime/assets/131360912/07082aad-dfef-4999-8acf-b04c860b1787




## 使用步驟
1. 先將影片每一幀的圖片丟到img資料夾
2. 執行image_to_txt.py
3. 編譯 anime_terminal.c
4. 把terminal視窗開到最大，然後按下space
## 圖片太大怎麼辦
可以到image_to_txt.py修改turn_img_to_txt的輸入fx和fy的數值，建議fx:fy是2:1

```python=
img_txt = turn_img_to_txt(img_dir_path + path, fx = 0.25, fy = 0.125)
```

## 動畫太慢或太快
可以更改usleep的延遲時間
```c=
usleep(21150); // 1e-6s
```

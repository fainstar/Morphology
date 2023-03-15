#include "MyForm.h"
#include "stdio.h"
#include "time.h"
#define black  0
#define white  255


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Drawing::Design;


void test(void) {
	printf("test");
}


/*膨脹*/
Bitmap^ Project1::dilate(Bitmap^ Input_image, int scope) {
	int time = clock();
	int blank = (scope - 1) / 2;
	Bitmap^  Output_image = gcnew Bitmap(Input_image->Width, Input_image->Height, Input_image->PixelFormat);
	BitmapData^ Data_I = Input_image->LockBits(Rectangle(0, 0, Input_image->Width, Input_image->Height), ImageLockMode::ReadWrite, Input_image->PixelFormat);
	BitmapData^ Data_O = Output_image->LockBits(Rectangle(0, 0, Output_image->Width, Output_image->Height), ImageLockMode::ReadWrite, Output_image->PixelFormat);
	Byte* Ptr_I = (Byte*)((void*)Data_I->Scan0);
	Byte* Ptr_O = (Byte*)((void*)Data_O->Scan0);
	int x, y, i, j, index, index2;
	for (x = 1; x < Data_I->Width - 1; x++) {
		for (y = 1; y < Data_I->Height - 1; y++) {
			index = y * Data_I->Stride + x * 3;
			Ptr_O[index + 0] = Ptr_I[index + 0];//複製
			Ptr_O[index + 1] = Ptr_I[index + 1];
			Ptr_O[index + 2] = Ptr_I[index + 2];
			if (Ptr_I[index] == black) { //如果輸入像素是黑色
				for (i = x - blank; i <= x + blank; i++) {//檢查周圍
					for (j = y - blank; j <= y + blank; j++) {
						index2 = j * Data_I->Stride + i * 3;
						if (x > blank && y > blank && x < (Data_I->Width - blank) && y < (Data_I->Height - blank)) {//邊緣
							if (Ptr_I[index2] == white) { //如果附近像素是白色
								Ptr_O[index + 0] = white;
								Ptr_O[index + 1] = white;
								Ptr_O[index + 2] = white;
								break;
							}
						}
					}
				}
			}
		}
	}
	Input_image->UnlockBits(Data_I);
	Output_image->UnlockBits(Data_O);
	time = clock() - time;
	printf("Dilation 範圍(%d*%d) 時間%d(ms)\n",scope,scope,time);
    return Output_image;
}


/*侵蝕*/
Bitmap^ Project1::erode(Bitmap^ Input_image, int scope) {
	int time = clock();
	int blank = (scope - 1) / 2;
	Bitmap^ Output_image = gcnew Bitmap(Input_image->Width, Input_image->Height, Input_image->PixelFormat);
	BitmapData^ Data_I = Input_image->LockBits(Rectangle(0, 0, Input_image->Width, Input_image->Height), ImageLockMode::ReadWrite, Input_image->PixelFormat);
	BitmapData^ Data_O = Output_image->LockBits(Rectangle(0, 0, Output_image->Width, Output_image->Height), ImageLockMode::ReadWrite, Output_image->PixelFormat);
	Byte* Ptr_I = (Byte*)((void*)Data_I->Scan0);
	Byte* Ptr_O = (Byte*)((void*)Data_O->Scan0);
	int x, y, i, j, index, index2,flag;
	for (x = 1; x < Data_I->Width - 1; x++) {
		for (y = 1; y < Data_I->Height - 1; y++) {
			index = y * Data_I->Stride + x * 3;
			Ptr_O[index + 0] = Ptr_I[index + 0];//複製
			Ptr_O[index + 1] = Ptr_I[index + 1];
			Ptr_O[index + 2] = Ptr_I[index + 2];
			flag = 0;
			if (Ptr_I[index] == white) { //如果輸入像素是白色
				for (i = x - blank; i <= x + blank; i++) {//檢查周圍
					for (j = y - blank; j <= y + blank; j++) {
						index2 = j * Data_I->Stride + i * 3;
						if (x > blank && y > blank && x < (Data_I->Width - blank) && y < (Data_I->Height - blank)) {//邊緣
							if (Ptr_I[index2] != white) { //如果附近像素不是白色
								flag = 1;
								break;
							}
						}
					}
				}
				if (flag == 1) {
					Ptr_O[index + 0] = black;
					Ptr_O[index + 1] = black;
					Ptr_O[index + 2] = black;
				}
			}
		}
	}
	Input_image->UnlockBits(Data_I);
	Output_image->UnlockBits(Data_O);
	time = clock() - time;
	printf("Erosion 範圍(%d) 時間%d(ms)\n", scope, time);
	return Output_image;
}
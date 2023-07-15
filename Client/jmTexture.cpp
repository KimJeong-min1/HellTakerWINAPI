#include "jmTexture.h"
#include "jmApplication.h"
#include "jmResources.h"


extern jm::Application application;

namespace jm
{
	Texture::Texture()
		: mImage(nullptr)
		, mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
		, mType(eTextureType::None)
	{
	}
	Texture::~Texture()
	{
	}

	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image != nullptr)
			return image;

		image = new Texture();
		image->SetWidth(width);
		image->SetHeight(height);
		HDC hdc = application.GetHdc();
		HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
		image->SetHBitmap(bitmap);

		HDC bitmapHdc = CreateCompatibleDC(hdc);
		image->SetHdc(bitmapHdc);

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(bitmapHdc, bitmap);
		DeleteObject(defaultBitmap);

		image->SetName(name);
		Resources::Insert<Texture>(name, image);

		return image;
	}
	
	HRESULT Texture::Load(const std::wstring& path)
	{
		//bmp 일때
		//png 일때

		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0
				, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			if (info.bmBitsPixel == 32)
				mType = eTextureType::AlphaBmp;

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);
			
			HBITMAP deafultBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(deafultBitmap);
		}
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());


			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
			
			
			/*::Image* Texture = Image::FromFile(path.c_str());
			::Graphics g(hdc);*/

			//g.DrawImage(image, x, y, width, height);

			//delete image;
			//ReleaseDC(hWnd, hdc);
		}
		

		return S_OK;
	}
}
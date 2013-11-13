//=================================================================================================
// Copyright 2013 Dirk Lemstra <http://magick.codeplex.com/>
//
// Licensed under the ImageMagick License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
//
//   http://www.imagemagick.org/script/license.php
//
// Unless required by applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing permissions and
// limitations under the License.
//=================================================================================================
#include "Stdafx.h"
#include "ImageProfile.h"
#include "..\IO\MagickReader.h"

namespace ImageMagick
{
	//==============================================================================================
	array<Byte>^ ImageProfile::Copy(array<Byte>^ data)
	{
		Throw::IfNullOrEmpty("data", data);

		array<Byte>^ result = gcnew array<Byte>(data->Length);
		data->CopyTo(result, 0);
		return result;
	}
	//==============================================================================================
	void ImageProfile::Initialize(String^ name, array<Byte>^ data)
	{
		Throw::IfNullOrEmpty("name", name);
		Throw::IfNullOrEmpty("data", data);

		_Name = name;
		_Data = data;
	}
	//==============================================================================================
	void ImageProfile::Initialize(MagickImage^ image)
	{
		(image);
	}
	//==============================================================================================
	array<Byte>^ ImageProfile::Data::get()
	{
		return _Data;
	}
	//==============================================================================================
	ImageProfile::ImageProfile(String^ name, array<Byte>^ data)
	{
		Initialize(name, Copy(data));
	}
	//==============================================================================================
	ImageProfile::ImageProfile(String^ name, Stream^ stream)
	{
		Initialize(name, MagickReader::Read(stream));
	}
	//==============================================================================================
	ImageProfile::ImageProfile(String^ name, String^ fileName)
	{
		Initialize(name, MagickReader::Read(fileName));
	}
	//==============================================================================================
	String^ ImageProfile::Name::get()
	{
		return _Name;
	}
	//==============================================================================================
	array<Byte>^ ImageProfile::ToByteArray()
	{
		array<Byte>^ result = gcnew array<Byte>(_Data->Length);
		if (_Data->Length > 0)
			_Data->CopyTo(result, 0);
		return result;
	}
	//==============================================================================================
}
/* KtxFile.h
Copyright (c) 2026 by thewierdnut

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#pragma once

#include <cstdint>
#include <string>

/**
 *  Reads a compressed texture from a texture file.
 */
class KtxFile
{
public:
	KtxFile(const std::string& src_data);

	bool Valid() const { return header != nullptr; }

	uint32_t InternalFormat() const;
	uint32_t Width() const;
	uint32_t Height() const;
	uint32_t OriginalWidth() const {return original_width; }
	uint32_t OriginalHeight() const {return original_height; }
	uint32_t Frames() const;
	uint32_t Size() const;

	const void* Data() const;

private:
	const struct ktx_header* header = nullptr;
	uint32_t original_width = 0;
	uint32_t original_height = 0;
};
/**
 * @file
 *
 * @brief Class encapsulating the executable being dissassembled.
 *
 * @copyright Assemblize is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            3 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#include <map>
#include <memory>
#include <string>

namespace LIEF
{
class Binary;
}

namespace unassemblize
{
class Executable
{
    struct SectionInfo
    {
        const uint8_t *data;
        uint64_t address;
        uint64_t size;
    };

public:
    Executable(const char *file_name);
    const uint8_t *section_data(const char *name) const;
    uint64_t section_address(const char *name) const;
    uint64_t section_size(const char *name) const;
    uint64_t base_address() const;
    uint64_t size() const;

private:
    std::unique_ptr<LIEF::Binary> m_binary;
    std::map<std::string, SectionInfo> m_sections;
};
}
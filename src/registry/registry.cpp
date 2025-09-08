#include "registry/registry.h"

namespace win
{

Registry::Registry(std::string_view hive)
    : m_hive{hive}
{
}

}

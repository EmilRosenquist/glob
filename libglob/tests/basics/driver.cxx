#include <libglob/version.h>
#include <glob/glob.h>

#undef NDEBUG
#include <cassert>
int main ()
{
  // Basics.
  {
    const auto dummy = std::filesystem::temp_directory_path() / "dummy" / "dummy";
    auto errorCode = std::error_code{};
    std::filesystem::create_directories(dummy, errorCode);
    if (!errorCode)
    {
      const auto matchingEntries = glob::glob(dummy.parent_path().string() + "/*");
      assert (!matchingEntries.empty());
    }
  }
}

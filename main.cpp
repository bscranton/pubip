#include <fmt/core.h>
#include <cpr/cpr.h>

int main(int argc, char **argv) {
	cpr::Response r = cpr::Get(cpr::Url{"https://api.ipify.org"});
	if (r.status_code == 200)
		fmt::println("Your public IP is {}.", r.text);
	else
		fmt::println("Unable to retrieve your public IP. HTTP {}", r.status_code);
	return 0;
}

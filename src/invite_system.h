#ifndef INVITE_SYSTEM_H
#define INVITE_SYSTEM_H

#include <string>
#include <vector>

bool validateCode(std::string code);
std::vector<std::string> generateInviteCodes(std::string inviterCode);
void createUser(std::string code, std::string role, std::string name);
std::vector<std::string> getInvitees(std::string inviterPrefix);

#endif
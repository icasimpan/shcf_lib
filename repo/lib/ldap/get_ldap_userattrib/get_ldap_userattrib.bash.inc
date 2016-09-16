get_ldap_userattrib() {
  local ldap_server=$1
  local ldap_user=$2
  local user_attrib=$3

  local retval=$($LDAPSEARCH_BIN -x -H $ldap_server "uid=$ldap_user"|$AWK_BIN -F' '  "/^$user_attrib:/ {print \$2}")

  echo $retval
} ## END: get_ldap_userattrib()

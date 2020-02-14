from collections import OrderedDict


def dfs(given_map, curr_map, root_id, level):

    # print - equal to level
    print("-"*level, end="")
    print(given_map[root_id]["name"])

    if root_id in curr_map:
        children = curr_map[root_id]

        # Order children map before printing it
        children = OrderedDict(sorted(children.items(), key=lambda x: given_map[x[0]]["name"]))

        for child_key, child_value in children.items():
            dfs(given_map, curr_map[root_id], child_key, level+1)
    return


def find_parent_ids(given_map, parent_id, parent_list):

    while parent_id != -1:
        parent_list.insert(0, parent_id)
        parent_id = given_map[parent_id]["parent_id"]

    return


def categorize(role_list):

    for role in role_list:
        if not role["parent_id"]:
            role["parent_id"] = -1

    # sort role list by parent id
    role_list_sorted = sorted(role_list, key=lambda x: x["parent_id"])

    # Overview of all key value pairs
    given_map = {}
    for role in role_list:
        given_map[role["id"]] = role

    # Main map containing map of maps
    root_map = {}

    for role in role_list_sorted:
        if role["parent_id"] == -1:
            root_map[role["id"]] = {}
            continue

        # a child, find path of parents from root to before leaf
        parent_id = role["parent_id"]
        parent_list = []
        find_parent_ids(given_map, parent_id, parent_list)

        curr_map = root_map
        for idx in range(len(parent_list)):
            curr_node_id = parent_list[idx]
            if curr_node_id in curr_map:
                curr_map = curr_map[curr_node_id]
        curr_map[role["id"]] = {}

    # Print map alphabetically ordered way
    root_map = OrderedDict(sorted(root_map.items(), key=lambda x: given_map[x[0]]["name"]))
    for key, value in root_map.items():
        # DFS on each parent
        dfs(given_map, root_map, key, 0)

    return


temp = [
  {"id": 1, "name": "Engineer", "parent_id": None},
  {"id": 3, "name": "Software Engineer", "parent_id": 1},
  {"id": 2, "name": "Front-End Engineer", "parent_id": 3},
  {"id": 4, "name": "Mechanical Engineer", "parent_id": 1},
  {"id": 5, "name": "UX Designer", "parent_id": 6},
  {"id": 6, "name": "Designer", "parent_id": None}
]

categorize(temp)


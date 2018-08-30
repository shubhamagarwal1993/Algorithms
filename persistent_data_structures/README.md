## About
  - A persistent data structure is a data structure that always preserves the previous version of itself when it is modified

#### Types of persistent
  - Partially persistent
    - A data structure is partially persistent if all versions can be accessed but only the newest version can be modified
    - They can be considered as ‘immutable’ as updates are not in-place
  - Fully persistent
    - A data structure is fully persistent if every version can be both accessed and modified
  - Confluently persistent
    - A data structure is confluently persistent when we merge two or more versions to get a new version
    - This induces a DAG on the version graph



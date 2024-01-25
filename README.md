# SC-component-manager

**SC-component-manager** is a part of [**sc-machine**](https://github.com/ostis-ai/sc-machine).
It allows ostis-systems to install reusable components for intelligent systems made with the [**OSTIS Technology**](https://github.com/ostis-ai/ostis-project).

## Installation
There are two possible ways:

1. Using ostis-web-platform
```sh
   git clone https://github.com/ostis-ai/ostis-web-platform
   cd ostis-web-platform/scripts
   git checkout feature/component_manager
   ./install_platform_with_component_manager.sh
```

2. Using sc-machine

```sh
# clone sc-machine
git clone git@github.com:ostis-ai/sc-machine.git
cd sc-machine

# checkout to the component_manager branch
git checkout component_manager
# install submodules
git submodule update --init --recursive
./scripts/install_deps_ubuntu.sh --dev
```

## Build
To build sc-machine with sc-component-manager run build script with component manager flag:

```sh
./scripts/build_sc_machine.sh -cm
```

To build knowledge base, run ```./build_kb``` in sc-machine or in ostis-web-platform scripts

## Post Install

### Debug Logs
To see sc-component-manager debug logs set `log_level` to `Debug` in `[sc-memory]` section of `sc-machine.ini`

### Common issues:
- Can't load a whole repo using the command `components install --idtf <component_identifier>`. There is only a repository directory without source files.
  
  **Solution**: please make sure your Git is configured to be able to use `git sparse-checkout`.
  ```sh
  git config --global core.sparseCheckoutCone true
  git config --global core.sparseCheckout true
  git config --global index.sparse true
  ```
  You can see more in the [official documentation](https://git-scm.com/docs/git-sparse-checkout).

## Usage

### Start sc-component manager

To start sc-component-manager run:

``./scripts/run_sc_component_manager.sh -c <CONFIG_PATH>``

Possible run flags:
- `-i` - interactive mode to run command manually;

### Commands

- `components init` - download specifications from repositories. `kb/specifications.scs` contains an example of a repository specification.
- `components search  [--author \<author\>][--class \<class\>][--explanation \<"explanation"\>]` - search a component specification in the knowledge base. You can search components by author, class or explanation substring.
- `components install [--idtf \<system_idtf\>]` - install component by its system identifier.

## Repository and components

File specification.scs contains description of two sections: **components** and **repositories**.

**Repositories** have links for source (GitHub, google drive etc.) with specification file, **components** have links to source with specification of component.

### Repository specification

Example of repository (`specifications.scs`)

```scs
sc_component_manager_repository
  <- concept_repository;
  -> rrel_components_specifications: ..components_addresses;
  -> rrel_repositories_specifications: ..repositories_addresses;;

..components_addresses
  <- sc_node_tuple;
  -> knowledge_base_ims_specification
    (*
      <- concept_reusable_component_specification;;
      => nrel_alternative_addresses:
      ...
      (*
        <- sc_node_tuple;;
        -> rrel_1:
          ... 
          (*
            -> [https://github.com/ostis-ai/ims.ostis.kb]
              (*
                <- concept_github_url;;
              *);;
          *);;
      *);;
    *);
  -> cat_kb_component_spec
      (*
           <- concept_reusable_component_specification;;
           => nrel_alternative_addresses:
           ...
           (*
                <- sc_node_tuple;;
                -> rrel_1:
                ...
                (*
                  -> [https://github.com/MksmOrlov/cat-kb-component]
                      (*
                        <- concept_github_url;;
                      *);;
                *);;
            *);;
        *);;

..repositories_addresses
  -> ... 
      (*
      -> rrel_address:
          [https://github.com/MksmOrlov/components-repo-example];;
      *);;
```

### Component specification

Example of components specification (`specification.scs`)

```scs
cat_specification
    <- concept_reusable_component_specification;;

cat_specification = [*
concept_cat
    <- concept_reusable_component;
    <- concept_atomic_reusable_component;
    <- concept_independent_reusable_component;
    <- concept_reusable_kb_component;
    <- concept_reusable_dynamically_installed_component;
    <- concept_reusable_source_code_component;

    => nrel_sc_identifier: [Cat specification](* <- lang_en;; *);
    => nrel_key_sc_element: concept_animal;
    => nrel_purpose: [Cat specification is needed to design knowledge bases about animal world, pets and zoo.](* <- lang_en;; *);
    => nrel_explanation: [Meow meow meow!] (*<- lang_en;; *);
    => nrel_authors: ... (* -> Orlov;; *);
    => nrel_component_dependencies: ... (* <- empty_set;; *);

    => nrel_component_address: [https://github.com/MksmOrlov/cat-kb-component] (* <- concept_github_url;; *);
    => nrel_installation_method: ... (* <- concept_component_dynamically_installed_method;; *);;
*];;
```

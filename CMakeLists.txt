

cmake_minimum_required(VERSION 3.8)

project ("sample_package")

add_executable(sample_package)

target_sources(sample_package

    PRIVATE 

        "main.cpp"
        "module/utils.cpp"
)





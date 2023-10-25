import pandas

path = 'G:/data/HOW_TEMP_SEX_ECO_NB_A.csv'

data = pandas.read_csv(path)
data = data[['ref_area', 'sex', 'classif1', 'time', 'obs_value']]
print(data)

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")
].sort_values(by='obs_value', ascending = False)[:10])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")
].sort_values(by='obs_value', ascending = False)[:10])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_M")
].sort_values(by='obs_value', ascending = True)[:10])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_F")
].sort_values(by='obs_value', ascending = True)[:10])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")
])

mean_value = data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")
].obs_value.mean()

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.obs_value > mean_value)
])

print(data[
    (data.classif1 == "ECO_AGGREGATE_TOTAL")&
    (data.sex == "SEX_T")&
    (data.obs_value < mean_value)
])

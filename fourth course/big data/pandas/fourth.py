import matplotlib.pyplot as plt
import numpy as np
import pandas

plt.rc('font', size=18)
X = np.linspace(0,1)
Y = X**3 - X**2 - 2
plt.plot(X, Y)
plt.show()

path = 'G:/data/EAR_4MTH_SEX_ECO_CUR_NB_A.csv'
data = pandas.read_csv(path)

data = data [ (data.ref_area != "BLR") & (data.ref_area != "ZWE")]
data = data[ ['ref_area', 'sex', 'classif1', 'classif2', 'time', 'obs_value']]
data = data [ (data.classif1 == "ECO_AGGREGATE_TOTAL") & (data.sex == "SEX_T")]
data_rus = data[data.ref_area == "RUS"]
data_rus = data_rus.set_index('time').sort_index()


pivot = data_rus.pivot_table(
values='obs_value',
index='time',
columns='classif2')

pivot.plot(
title='Среднемесячная зарплата в России по годам',
kind='bar',
logy=True,
subplots=False)

pivot.loc[
    pivot.index <= 1996, 'CUR_TYPE_LCU'] /= 1000

pivot.plot(
    title = 'Среднемесячная зарплата в России по годам',
    kind='bar',
    subplots = True)

data_cpi = pandas.read_csv('G:/data/CPI_NCYR_COI_RT_A.csv')

data_cpi = data_cpi[data_cpi.classif1 == 'COI_COICOP_CP01T12'][['ref_area', 'time', 'obs_value']]

data_cpi = data_cpi.rename(columns = {'obs_value' : 'cpi_change'})

data_cpi = data_cpi.set_index(['ref_area', 'time'])

print(data_cpi.loc['RUS'])
data_cpi.loc['RUS'].sort_index()[['cpi_change']].plot(title = 'Инфляция (изм. ИПЦ в %) в Рщссии по годам (ILO)',
    kind = 'bar')

data = data.join(data_cpi, on=['ref_area', 'time'])
print(data)

data[
     (data.ref_area == 'RUS')&
     (data.time > 1992)
].set_index('time').sort_index()[['obs_value', 'cpi_change']].plot(
    title = 'Зарплата (LCU) vs инфляция (в %) в России по годам (ILO)',
    kind = 'bar',
    subplots = True)

data_cpi['cpi_value'] = data_cpi.cpi_change + 100
data_cpi['cpi_factor'] = data_cpi.cpi_value / 100

data_cpi_1993 = data_cpi.loc[data_cpi.index.get_level_values(1) > 1992]
data_cpi_1993['cpi_factor_1992'] = data_cpi_1993.sort_index().groupby(by = ['ref_area'])['cpi_factor'].cumprod()
print(data_cpi_1993.loc[['RUS', 'USA']])

data_cpi_1993.loc['RUS'].sort_index()[['cpi_factor', 'cpi_factor_1992']].plot(
    title = 'Ежегодная инфляция и инфляция по отношению к 1992 в России',
    kind = 'bar',
    subplots = True)

data = data.drop(columns = ['cpi_change'])
data = data.join(data_cpi_1993, on=['ref_area', 'time'])

data['wage_corr_cpi_1992'] = data.obs_value / data.cpi_factor_1992

data_rus_lcu_1993 = data[
    (data.ref_area == 'RUS') &
    (data.classif2 == 'CUR_TYPE_LCU') &
    (data.time >= 1993)
]

data_rus_lcu_1993.set_index('time').sort_index()[['obs_value', 'wage_corr_cpi_1992']].plot(
    title = 'Номинальная зарпата vs реальное содержание зарплаты в ценах 1992 в России',
    kind = 'bar',
    subplots = True)

data_rus_lcu_1993.loc[
    data_rus_lcu_1993.time >= 1997,
    ['obs_value', 'wage_corr_cpi_1992']
] *= 1000

data_rus_lcu_1993.set_index('time').sort_index()[['obs_value', 'wage_corr_cpi_1992']].plot(
    title = 'Номинальная зарпата vs реальное содержание зарплаты в ценах 1992 в России',
    kind = 'bar',
    subplots = True)




data_cpi['cpi_retro_factor'] = 1 / data_cpi.sort_index(ascending = False).groupby(by = ['ref_area'])['cpi_factor'].shift(fill_value = 1)
data_cpi_2019_retro = data_cpi.loc[data_cpi.index.get_level_values(1) <= 2019]
data_cpi_2019_retro.loc[
    data_cpi_2019_retro.index.get_level_values(1) == 2019,
    'cpi_retro_factor'] = 1
data_cpi_2019_retro['cpi_retro_factor_2019'] = data_cpi_2019_retro.sort_index(ascending = False).groupby(by = ['ref_area'])['cpi_retro_factor'].cumprod()
data = data.join(
    data_cpi_2019_retro[['cpi_retro_factor', 'cpi_retro_factor_2019']],
    on = ['ref_area', 'time'])
data['wage_corr_retro_cpi_2019'] = data.obs_value / data.cpi_retro_factor_2019

data[ (data.ref_area == 'RUS') & (data.classif2 == 'CUR_TYPE_LCU') &
     (data.time > 1996) &
     (data.time <= 2019)].set_index('time').sort_index()[['obs_value', 'wage_corr_retro_cpi_2019']].plot(
         title = 'Зарплата в ценах 2019 в России',
         kind = 'bar')

data[ (data.ref_area == 'USA') & (data.classif2 == 'CUR_TYPE_LCU') &
     (data.time > 1996) &
     (data.time <= 2019)].set_index('time').sort_index()[['obs_value', 'wage_corr_retro_cpi_2019']].plot(
         title = 'Зарплата в ценах 2019 в США',
         kind = 'bar')

data[ (data.ref_area == 'CHN') & (data.classif2 == 'CUR_TYPE_LCU') &
     (data.time > 1996) &
     (data.time <= 2019)].set_index('time').sort_index()[['obs_value', 'wage_corr_retro_cpi_2019']].plot(
         title = 'Зарплата в ценах 2019 в Китае',
         kind = 'bar')

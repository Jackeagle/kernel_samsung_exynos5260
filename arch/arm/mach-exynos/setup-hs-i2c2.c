/*
 * Copyright (C) 2012 Samsung Electronics Co., Ltd.
 *
 * HS-I2C2 GPIO configuration.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/gpio.h>
#include <plat/gpio-cfg.h>
#include <plat/cpu.h>

void exynos5_hs_i2c2_cfg_gpio(struct platform_device *dev)
{
	if (soc_is_exynos5250())
		s3c_gpio_cfgall_range(EXYNOS5_GPA0(6), 2,
			S3C_GPIO_SFN(4), S3C_GPIO_PULL_UP);
	else if (soc_is_exynos5260())
		s3c_gpio_cfgall_range(EXYNOS5260_GPB3(4), 2,
				S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
	else if (soc_is_exynos5410())
		s3c_gpio_cfgall_range(EXYNOS5410_GPB1(3), 2,
				S3C_GPIO_SFN(4), S3C_GPIO_PULL_UP);
	else if (soc_is_exynos5420())
		s3c_gpio_cfgall_range(EXYNOS5420_GPB1(3), 2,
				S3C_GPIO_SFN(4), S3C_GPIO_PULL_UP);
	else
		pr_err("failed to configure gpio for hs-i2c2\n");
}

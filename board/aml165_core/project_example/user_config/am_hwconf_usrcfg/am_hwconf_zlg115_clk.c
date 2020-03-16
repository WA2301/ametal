/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ZLG116 ʱ���û������ļ�
 * \sa am_hwconf_zlg116_clk.c
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-13  sdy, first implementation.
 * \endinternal
 */
 
#include "am_zlg115_clk.h"
#include "hw/amhw_zlg115_rcc.h"
#include "hw/amhw_zlg116_rcc.h"

/**
 * \addtogroup am_if_src_hwconf_zlg116_clk
 * \copydoc am_hwconf_zlg116_clk.c
 * @{
 */

/** \brief CLK ƽ̨��ʼ�� */
static void __zlg115_clk_plfm_init (void)
{

}

/**
 * \brief CLK�豸��Ϣ
 */
static const am_zlg115_clk_devinfo_t __g_clk_devinfo =
{

    /**
     * \brief ʱ������Ƶ��
     *    ��SYSʱ��Ϊ HSE  ��������ֵΪ�û��ⲿ�����ʵ��Ƶ��
     *    ��SYSʱ��Ϊ HSI  �����������Ϊ�ڲ�����Ƶ��ѡ���������Ƶ�ʿɹ�ѡ��
     *                       AM_ZLG115_HSI_72M�� AM_ZLG115_HSI_48M
     */
     AM_ZLG115_HSI_48M,

    /** \brief
     *    SYS ʱ��Դѡ��
     *    -# AMHW_ZLG115_SYSCLK_HSI_DIV6 : HSI ����  6 ��Ƶ��Ϊϵͳʱ��
     *    -# AMHW_ZLG115_SYSCLK_HSE      : HSE ��Ϊϵͳʱ��
     *    -# AMHW_ZLG115_SYSCLK_HSI      : HSI ��Ϊϵͳʱ��
     *    -# AMHW_ZLG115_SYSCLK_LSI      : LSI ��Ϊϵͳʱ��
     */
    AMHW_ZLG115_SYSCLK_HSI,

    /**
     * \brief AHB��Ƶϵ����AHBCLK = PLLOUT / DIV,AHB���Ƶ��Ϊ48Mhz
     *
     *    ahb_div |  DIV
     *   ---------------------
     *        0-7 |   1
     *        8   |   2
     *        9   |   4
     *        10  |   8
     *        11  |   16
     *        12  |   64
     *        13  |  128
     *        14  |  256
     *        15  |  512
     */
    0,

    /**
     * \brief APB1��Ƶϵ����APB1CLK = AHBCLK / (2 ^ apb1_div)
     *        APB1���Ƶ��Ϊ24Mhz
     */
    1,

    /**
     * \brief APB2��Ƶϵ����APB2CLK = AHBCLK / (2 ^ apb2_div)
     *        APB2���Ƶ��Ϊ48Mhz
     */
    0,

    /* ƽ̨��ʼ������������ʱ�����ŵȲ��� */
    __zlg115_clk_plfm_init,

    /* CLK��ƽ̨ȥ��ʼ������ */
    NULL
};

/** \brief ʱ���豸ʵ�� */
static am_zlg115_clk_dev_t __g_clk_dev;

/**
 * \brief CLK ʵ����ʼ������ʼ��ϵͳʱ��
 * \retval AM_OK : ʱ�ӳɹ���ʼ��
 */
int am_zlg115_clk_inst_init (void)
{
    return am_zlg115_clk_init(&__g_clk_dev, &__g_clk_devinfo);
}

/**
 * @}
 */

/* end of file */